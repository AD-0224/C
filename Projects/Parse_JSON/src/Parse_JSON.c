#include"PARSE_JSON.h"

void skip_whitespace(char **json)
{
    while (**json == 32 || **json == 9 || **json == 10 || **json == 13)
        (*json)++;
}
char *parse_string(char **json) //enlever les guillemets
{
    (*json)++;
    int len = 0; //compteur 

    char *temp = *json;
    while (*temp && *temp != '"')
    {
        if (*temp =='\\' && *(temp + 1))
        {
            temp += 2;
            len++;
        }
        else 
        {
            temp++;
            len++;
        }
    }
    char *str = malloc(len + 1);
    if(!str)    exit(EXIT_FAILURE);
    int i = 0;
    while(**json && **json != '"')
    {
        if (**json == '\\')
        {
            (*json)++;
            switch (**json)
            {
                case 'n' : str[i++] = '\n'; break;
                case 't': str[i++] = '\t'; break;
                case '"': str[i++] = '"'; break;
                case '\\': str[i++] = '\\'; break;
                default: str[i++] = **json;
            }
            (*json)++;
        }
        else 
            str[i++] = *((*json)++);
    }
    str[i] = '\0';
    (*json)++;
    return str;
}

double parse_number(char **json)
{
    char buffer[64];
    int i = 0; //index ecriture dans le buffer

     if (**json == '-')
     {
        buffer[i++] = '-';
        (*json)++;
     }
    while ((**json >= '0' && **json <= '9') || (**json == '.'))
    {
        buffer[i++] = **json; // on le copie dans le buffer
        (*json)++; 
    }
    buffer[i] = '\0';
    return atof(buffer); //asci  to float "213.6" -> 213.6
}

int parse_boolean(char **json)
{
    if (strncmp(*json, "true", 4) == 0) 
    {
        *json += 4;
        return 1;    // vrai
    }
    else if (strncmp(*json, "false", 5) == 0)
    {
        *json += 5;
        return 0; // faux
    }
    return -1; 
}
JSONArray* parse_array(char **json)
{
    if (**json != '[')
        return NULL;
    (*json)++;
    skip_whitespace(json);

    JSONArray *array = malloc(sizeof(JSONArray));  //crée la structure
    if (!array) exit(EXIT_FAILURE);
    
    array->items = NULL;                           //initialise
    array->count = 0;

    if (**json == ']')          //array vide []
    {                     
        (*json)++;
        return array;
    }

    while (**json && **json != ']')
    {
        JSONValue *value = parse_value(json);
        if (!value) return array;

        array->items = realloc(array->items, sizeof(JSONValue*) * (array->count + 1));  //grandit dynamiquement
        array->items[array->count++] = value;      //stocke la valeur

        skip_whitespace(json);

        if (**json == ',')
        {
            (*json)++;
            skip_whitespace(json);
        } 
        else if (**json != ']')
        {
            break;
        }
    }
    if (**json == ']')
        (*json)++;
    return array;
}
JSONObject* parse_object(char **json)
{
    if (**json != '{') 
        return NULL;
    
    (*json)++;  // sauter '{'
    skip_whitespace(json);
    JSONObject *obj = malloc(sizeof(JSONObject));
    if (!obj) exit(EXIT_FAILURE);
    
    obj->pairs = NULL; //initialisation
    obj->count = 0;    //iitialisation
    if (**json == '}')  // objet vide {}
    {
        (*json)++;
        return obj;
    }
    while (**json && **json != '}')
    {
        //lire la clé (toujours une string)
        if (**json == '"')
        {
            char *key = parse_string(json);
            skip_whitespace(json);
            if (**json == ':')
            {
                (*json)++;
                skip_whitespace(json);
                JSONValue *value = parse_value(json);
                if (!value)
                {
                    free(key);
                    return obj;
                }
                obj->pairs = realloc(obj->pairs, sizeof(JSONPair) * (obj->count + 1));
                obj->pairs[obj->count].key = key;
                obj->pairs[obj->count].value = value;
                obj->count++;
            }
            else
            {
                printf("Erreur : ':' attendu après la clé\n");
                free(key);
                return obj;
            }
        }
        skip_whitespace(json);
        if (**json == ',')
        {
            (*json)++;
            skip_whitespace(json);
        }
        else if (**json != '}')
        {
            break;
        }
    }
    if (**json == '}')
        (*json)++;
    
    return obj;
}

JSONValue* parse_value(char **json)
{  
    skip_whitespace(json);

    JSONValue *value = malloc(sizeof(JSONValue));
    if (!value) exit(EXIT_FAILURE);

    if (**json == '"')      // ← Chaîne
    {                     
        value->type = JSON_STRING;
        value->data.string = parse_string(json);
    }
    else if (**json == '[')     // ← Array
    {            
        value->type = JSON_ARRAY;
        value->data.array = parse_array(json);
    }
    else if (**json == '{')       // ← Objet
    {             
        value->type = JSON_OBJECT;
        value->data.object = parse_object(json);
    }
    else if (**json == 't' || **json == 'f')    // ← Boolean
    { 
        value->type = JSON_BOOLEAN;
        value->data.boolean_value = parse_boolean(json);
    }
    else if (**json == 'n')     //null
    { 
        JSONValue *null_val = parse_null(json);
        if (null_val)
        {
            free(value);
            return null_val;
        }
    }
    else if (**json == '-' || (**json >= '0' && **json <= '9'))     //Nombre
    { 
        value->type = JSON_NUMBER;
        value->data.number = parse_number(json);
    }
    else
    {
        free(value);
        return NULL;
    }
    return value;
}

JSONValue* parse_null(char **json)
{
    if (strncmp(*json, "null", 4) == 0)
    {
        *json += 4;
        JSONValue *value = malloc(sizeof(JSONValue));
        if (!value) exit(EXIT_FAILURE);
        value->type = JSON_NULL;
        return value;
    }
    return NULL;
}

void free_value(JSONValue *value)
{
    if (!value) return;
    
    if (value->type == JSON_STRING)
    {
        free(value->data.string);
    }
    else if (value->type == JSON_ARRAY) //double pointeur donc boucle et on free de l'enfant au parent 
    {
        for (int i = 0; i < value->data.array->count; i++)
        {
            free_value(value->data.array->items[i]);
        }
        free(value->data.array->items);
        free(value->data.array);
    }
    else if (value->type == JSON_OBJECT)
    {
        for (int i = 0; i < value->data.object->count; i++)
        {
            free(value->data.object->pairs[i].key);
            free_value(value->data.object->pairs[i].value);
        }
        free(value->data.object->pairs);
        free(value->data.object);
    }
    free(value);
}

void print_value(JSONValue *value, int indent, int in_array)
{
    if (!value) return;

    switch (value->type)
    {
        case JSON_STRING:
            printf("\"%s\"", value->data.string);
            break;

        case JSON_NUMBER:
            printf("%g", value->data.number);
            break;

        case JSON_BOOLEAN:
            printf(value->data.boolean_value ? "true" : "false");
            break;

        case JSON_NULL:
            printf("null");
            break;

        case JSON_ARRAY:
        {
            printf("[");
            for (int i = 0; i < value->data.array->count; i++)
            {
                if (i > 0) printf(", ");
                print_value(value->data.array->items[i], 0, 1);
            }
            printf("]");
            break;
        }

        case JSON_OBJECT:
        {
            if (in_array) //flag
            {
                printf("{");
                for (int i = 0; i < value->data.object->count; i++)
                {
                    if (i > 0) printf(", ");
                    printf("\"%s\":", value->data.object->pairs[i].key);
                    print_value(value->data.object->pairs[i].value, 0, 0);
                }
                printf("}");
            }
            else
            {
                printf("{\n");
                for (int i = 0; i < value->data.object->count; i++)
                {
                    for (int j = 0; j < indent + 2; j++) printf(" ");
                    printf("\"%s\": ", value->data.object->pairs[i].key);
                    print_value(value->data.object->pairs[i].value, indent + 2, 0);
                    if (i < value->data.object->count - 1) printf(",");
                    printf("\n");
                }
                for (int j = 0; j < indent; j++) printf(" ");
                printf("}");
            }
            break;
        }
    }
}

