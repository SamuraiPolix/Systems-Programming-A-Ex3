#include "StrList.h"
#define MAX_CHARS 2047

#define INSERT_MANY_TO_LIST 1
#define INSERT_TO_SPECIFIC_INDEX 2
#define PRINT_LIST 3
#define PRINT_LIST_SIZE 4
#define PRINT_SPECIFIC_INDEX 5
#define PRINT_NUM_OF_CHARS 6
#define HOW_MANY_TIMES_STR_IN_LIST 7
#define REMOVE_STR_FROM_LIST 8
#define REMOVE_SPECIFIC_INDEX 9
#define REVERSE_LIST 10
#define DELETE_LIST 11
#define SORT_LEXI 12
#define CHECK_SORTED_LEXI 13
#define EXIT 0

/*
עליכםלספקגםתוכנית ראשית שתופיע בקובץMain.cובה יהיה תפריט שיתמוך באופציות
הבאות:
1-הכנסתמחרוזותלרשימה. בלחיצה עלAמכניסים כמה מיליםרוצים להכניס ואז מכניסים את
המילים ברצף, כאשר בין2מילים מפריד רווח. כל מילה חדשה תיכנס במקום האחרון ברשימה.
2-הכנסתמחרוזתבאינדקס מסוים, מקבלים אינדקס ואזמחרוזתומכניסים במקום המתאים.
3-הדפסת הרשימה
4–הדפסת אורך הרשימה
5-הדפסתמחרוזתבאינדקס מסוים
6-הדפסת מספרהתוויםשמופיעים בכל הרשימה
7-מקבליםמחרוזתומדפיסים כמה פעמים היא מופיעה
8-מקבליםמחרוזתומוחקים את כל המופעים מהרשימה
9-מקבלים אינדקס ומוחקים אתהאיבר המתאים.
10-הופכים את הרשימה.
11-מחיקתכל הרשימה.
12-סידורהרשימה לפי סדר לקסיקוגרפי.
13-בדיקה האם הרשימה מסודרת לפי סדר לקסיקוגרפי
0-לצאת מהתוכנית
*/

void removeLineBreak(char *);
 
int main() {
    int action;
    int numOfInputs, index;
    char word[2048];

    StrList* strList = StrList_alloc();

    if (strList == NULL){
        printf("%s\n", MEMORY_ALLOCATION_ERROR);
        return -1;
    }


    do {
        scanf("%d", &action);

        while ((getchar()) != '\n');       // Denies line breaks
        
        switch (action)
        {
            case INSERT_MANY_TO_LIST:
                scanf("%d", &numOfInputs);
                getchar();
                for (int i = 0; i < numOfInputs; i++){
                    scanf("%s ", word);
                    StrList_insertLast(strList, word);
                }
                break;
            case INSERT_TO_SPECIFIC_INDEX:
                scanf("%d", &index);
                getchar();
                fgets(word, MAX_CHARS, stdin);
                removeLineBreak(word);          // remove line break if exists
                StrList_insertAt(strList, word, index); 
                break;
            case PRINT_LIST:
                StrList_print(strList);
                break;
            case PRINT_LIST_SIZE:
                printf("%ld\n", StrList_size(strList));
                break;
            case PRINT_SPECIFIC_INDEX:
                scanf("%d", &index);
                StrList_printAt(strList, index);
                break;
            case PRINT_NUM_OF_CHARS:
                printf("%d\n", StrList_printLen(strList));
                break;
            case HOW_MANY_TIMES_STR_IN_LIST:
                fgets(word, MAX_CHARS, stdin);
                removeLineBreak(word);          // remove line break if exists
                printf("%d\n", StrList_count(strList, word));
                break;
            case REMOVE_STR_FROM_LIST:
                fgets(word, MAX_CHARS, stdin);
                removeLineBreak(word);          // remove line break if exists
                StrList_remove(strList, word);
                break;
            case REMOVE_SPECIFIC_INDEX:
                scanf("%d", &index);
                StrList_removeAt(strList, index);
                break;
            case REVERSE_LIST:
                StrList_reverse(strList);
                break;
            case DELETE_LIST:
                StrList_free(strList);
                strList = NULL;
                break;
            case SORT_LEXI:
                StrList_sort(strList);
                break;
            case CHECK_SORTED_LEXI:
                printf("%s\n", StrList_isSorted(strList) == 0 ? "false" : "true");
                break;
            case EOF:
            case EXIT:
                StrList_free(strList);
                return 0;
                break;        
            default:
                printf("ERROR: incorrect input!");
        }
    } while (action != 0);

    StrList_free(strList);

    return 0;
}

// Removes line break at the end of 'word', if exists
void removeLineBreak(char *word){
    if (strlen(word) > 0 && word[strlen(word)-1] == '\n'){
        word[strlen(word)-1] = 0;
    }
}