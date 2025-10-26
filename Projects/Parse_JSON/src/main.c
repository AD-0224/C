#include"PARSE_JSON.h"

int main(void)
{
    const char *json_str = "{\"nom\":\"Eren\",\"age\":21,\"actif\":true,\"notes\":[12,15.5,19],\"amis\":[{\"nom\":\"Armin\"},{\"nom\":\"Mikasa\"}],\"adresse\":null}";
    // const char *json_str = "{\"quote\":\"Il dit \\\"OK\\\"\"}";
    // const char *json_str =  "{\"text\":\"Ligne 1\\nLigne 2\\nLigne 3\"}";
    // const char *json_str = "{\"path\":\"C:\\\\Users\\\\data.txt\"}";
    // const char *json_str = "{\"msg\":\"Tab:\\there\\nNew line\"}";

    printf("Input:\n%s\n\n", json_str);

    char *json = (char *)json_str;
    JSONValue *root = parse_value(&json);

    if (root)
    {
        printf("Parsed output:\n");
        print_value(root, 0, 0);
        printf("\n");
    }
    else
    {
        printf("Parsing error.\n");
    }
    free_value(root);
    return 0;
}