int isVowel(char c)
{
    c = tolower(c);

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char *reverseVowels(char *s)
{
    int i = 0;
    int j = strlen(s) - 1;

    while (i < j)
    {
        if (isVowel(s[i]) && isVowel(s[j]))
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            i++;
            j--;
        }
        else if (!isVowel(s[i]))
        {
            i++;
        }
        else if (!isVowel(s[j]))
        {
            j--;
        }
    }

    return s;
}