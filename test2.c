int main() {
    char *sequencia = "5CaCvLzQNO9txqO8wb5CrtcI60WMELtE3YV7f6FJAPybmID8rYgQeXZSKVmp8YBUQDFe1g8Bm6sDOiESesFGHba1YtQnzGCMJkJzDfVDLar1LDfnUpoORFEvgPRPctWqfAuQ89spcLYI2wu9si09U38qiUY6GlAiEiKng4FkGAZitHII2qDX4hA7330DdoO7DFejpps14GzQ1RHflXoW8hUQ5EBkhFcq6cQpQHzSMpLmfbOzM4W0r912NW8PAYtLB4Jsv1yke5D3EQocdk8pwWVrSUakjgWnGlOPafvqoTFxMwMMsdDbnxW3UJiDZAFapuLVOcLWdwEmQAKKEBoBcoH1aNeenlWWKS6lfg6Wm7JuKP939i3ORxkFuYht9JknaeFagffcuADpg9e1pgshx9KdxH7f83dtJURXVkaIczOD9sx4j2yoj9XnY2g7BhDU5tBLZJOfRV6r5LKVM5u14G8lOmmxzkKFOk4l626wnjqDKynozmmrD3ADU68JubVAQKgu05jB34CtPbYpOv0VpKJ3UhkoC1hjNXkonyfaJ4BweT471YUKsQhLcaBcJ8u86FXRSFQndmFNTw56sSrSnK8l8lYta49tSXZFgRLSKtsHbyzMHGsdILJYwKiGWWuGHHWHswBXBup7YmVqXlhptjzt0HFpJJX5T2vU4MZ229QujVhSZnyKibK47Ar06rMXrtThxmq0RzAdt0P7qDXL1sT4RWWNMTZX0npwqVgHOFNoyFn1DPKKbYXk4DEAknZRulzUhEvvh3d5FLfzK3ac9a5C1X57SVxQVvIIKjqtR6Qfj00qyLjMp6US1KJYxW50ySh4mzE1ewy4DqMN40jRCStNyxFhVSaDLaHA0JdhAyqy48IQ616CIaiyYr8M0OcF7mFfjXSg0CdraZ5sxlob3POcda2m8Ih4EkWwK2HD7IltIGetpegVNzgbPhho0cUICv6ObjYxebcWf8IFoVRW4TrAYJwW2Y8iB1V6l8iozoVPnFvUjJSQx8sxtgewfEI0";
    
    char menor_substring[6]; // para armazenar a menor substring encontrada
    menor_substring[5] = '\0'; // garantindo que a string resultante esteja terminada

    // Inicializando a menor substring com os primeiros 5 caracteres da sequência
    strncpy(menor_substring, sequencia, 5);

    // Iterando pela sequência e comparando todas as substrings de 5 caracteres
    for (int i = 1; sequencia[i + 4] != '\0'; i++) {
        char substring[6];
        strncpy(substring, sequencia + i, 5);
        substring[5] = '\0'; // garantindo que a string resultante esteja terminada

        // Comparando a substring atual com a menor substring encontrada até agora
        if (strcmp(substring, menor_substring) < 0) {
            // Se a substring atual for menor, atualizamos a menor substring
            strcpy(menor_substring, substring);
        }
    }

    // Imprimindo a menor substring encontrada
    printf("Menor substring lexicográfica: %s\n", menor_substring);

    return 0;
}