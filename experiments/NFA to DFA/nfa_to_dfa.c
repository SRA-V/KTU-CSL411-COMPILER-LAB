#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CHARS 26
struct state
{
    char st[20];
} st[30];

int nt, nf, ns, ds = 0, dsp = 0;
char start, trans[20][3], final[20], sym[10];
bool are_same_chars(const char *str1, const char *str2)
{
    int char_count1[MAX_CHARS] = {0}, char_count2[MAX_CHARS] = {0};
    int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 != len2)
        return false;
    for (int i = 0; i < len1; i++)
    {
        char_count1[str1[i] - 'a']++;
        char_count2[str2[i] - 'a']++;
    }
    for (int i = 0; i < MAX_CHARS; i++)
        if (char_count1[i] != char_count2[i])
            return false;
    return true;
}
bool have_common_characters(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int char_count1[26] = {0};
    int char_count2[26] = {0};
    for (int i = 0; i < len1; i++) {
        char_count1[str1[i] - 'a']++;
    }
    for (int i = 0; i < len2; i++) {
        char_count2[str2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (char_count1[i] > 0 && char_count2[i] > 0) {
            return true;
        }
    }
    return false;
}
bool astate(char *str)
{
    for (int i = 0; i < ds; i++)
        if (are_same_chars(st[i].st, str))
            return true;
    return false;
}
bool isin(char *str, char c)
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == c)
            return true;
    return false;
}
void dfa()
{
    char s[20] = {'\0'};
    int p = 0, d = 0;
    while (ds != dsp)
    {
        for (int i = 0; i < ns; i++)
        {
            for (int k = 0; k < strlen(st[dsp].st); k++)
                for (int j = 0; j < nt; j++)
                    if (st[dsp].st[k] == trans[j][0] && trans[j][1] == sym[i])
                        if (!isin(s, trans[j][2]))
                        {
                            s[p] = trans[j][2];
                            s[++p] = '\0';
                        }
            if (p == 0)
            {
                printf("\n%s %c Dead", st[dsp].st, sym[i]);
                d = 1;
            }
            else
            {
                printf("\n%s %c %s", st[dsp].st, sym[i], s);
                if (!astate(s))
                {
                    strcpy(st[ds++].st, s);
                }
            }
            p = 0;
            s[p] = '\0';
        }
        dsp++;
    }
    if (d)
        for (int i = 0; i < ns; i++)
            printf("\nDead %c Dead", sym[i]);
}
void finals()
{
    printf("\nFinal states:{");
    for (int i = 0; i < ds; i++)
        if(have_common_characters(final,st[i].st))
        printf("%s,",st[i].st);
    printf("}");

}
int main()
{
    printf("Number of transitions and final state:\n");
    scanf("%d %d", &nt, &nf);
    printf("Start state:\n");
    scanf(" %c", &start);
    printf("Final states:\n");
    scanf("%s", final);
    printf("Symbols:\n");
    scanf("%s", sym);
    printf("Transitions:\n");
    for (int i = 0; i < nt; i++)
        scanf(" %c %c %c", &trans[i][0], &trans[i][1], &trans[i][2]);
    ns = strlen(sym);
    st[ds].st[0] = start;
    st[ds].st[1] = '\0';
    ds++;
    dfa();
    finals();
}
