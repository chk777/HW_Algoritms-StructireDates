#include <stdio.h>
#include <locale>

#define ENG 26 // для нахождения символов латинского алфавита
#define RUS 32 // для нахождения символов русского алфавита где Ё вне русского алфавита по таблице ASCII

// подготовим два файла input.txt для ввода кодируемоего текста, output.txt для зашифрованного текста
// данное пространство для шифрования символов
void encrypt (int n)
{
    FILE *fp1, *fp2;
    fopen_s(&fp1, "input.txt", "r");
    fopen_s(&fp2, "output.txt", "w");
    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1))
    {
        flag = 0; //обработан ли текущий символ
        if (c >= 'A' && c <= 'Z')
        {
            c = c + (n % ENG);
            if (c > 'Z') c = 'A' + (c - 'Z') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c + (n % ENG);
            if (c > 'z') c = 'a' + (c - 'z') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'А' && c <= 'Я')
        {
            c = c + (n % RUS);
            if (c > 'Я') c = 'А' + (c - 'Я') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c>='а' && c<='я')
        {
            c = c + (n % RUS);
            if (c > 'я') c = 'а' + (c - 'я') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf (fp2, "%c", c);
        c = getc(fp1);
    }
    fclose (fp1);
    fclose (fp2);
}
// теперь соответственно пространство для расшифровки текста
void decipher (int n)
{
    FILE *fp1, *fp2;
    fopen_s(&fp1, "input.txt", "r");
    fopen_s(&fp2, "output.txt", "w");
    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c - (n % ENG);
            if (c < 'A') c = 'Z' - ('A' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c - (n % ENG);
            if (c < 'a') c = 'z' - ('a' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'А' && c <= 'Я')
        {
            c = c - (n % RUS);
            if (c < 'А') c = 'Я' - ('А' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'а' && c <= 'я')
        {
            c = c - (n % RUS);
            if (c < 'а') c = 'я' - ('а' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf (fp2, "%c", c);
        c = getc(fp1);
    }
    fclose (fp1);
    fclose (fp2);
}

int main ()
{
    setlocale(LC_ALL,"Russian");
    int n; // ключ шифрования
    printf ("Введите натуральное n: ");
    scanf_s ("%d", &n);
    getchar (); //нужен для того, чтобы поймать символ клавиши ENTER, нажатой при вводе числа n
    if (n < 1) return 0;
    printf ("Чтобы зашифровать текст введите a, расшифровать b: ");
    char c;
    scanf_s ("%c", &c, 1);
    if (c == 'a') encrypt (n);
    if (c == 'b') decipher (n);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и количеством столбцов
    int i,t,l, a[100];

    char S[100]=” “, k[100]=” “, c[100]=” “;
    clrscr();
    puts(“Enter num:\n\n ”);
    gets(S);
    l=strlen(S);
    printf(“\n dlina=%d”,l);
    printf(“\n\n”);
    for(i=0;i<l;i++)
    {a[i]=rand()%l;
        for(t=0;t<i;i++)
            if (a[i]==a[t])
            {i--;
                break;
            }}
    puts(“\n key encr :\n\n”);
    for(i=0;i<l;i++)
        printf(“%d”,a[i]);
    puts(“\n encrided:\n\n”);
    for(i=0;i<l;i++)
    {c[i]=S[a[i]];
        printf(“%c”,c[i]);}
    puts(“\n decrided:\n\n”);
    for(i=0;i<l;i++)
    {k[a[i]]=c[i];
    }
    puts(k);
    getсh();
    return 0;
}
