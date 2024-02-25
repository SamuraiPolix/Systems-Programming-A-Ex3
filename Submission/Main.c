
#define INSERT_MANY_TO_LIST 1
#define INSERT_TO_SPECIFIC_INDEX 2
#define PRINT_LIST 3
#define PRINT_LIST_LENGTH 4
#define PRINT_SPECIFIC_INDEX 5
#define PRINT_NUM_OF_CHARS 6
#define HOW_MANY_TIMES_STR_IN_LIST 7
#define REMOVE_STR_FROM_LIST 8
#define REMOVE_SPECIFIC_INDEX 9
#define INVERT_LIST 10
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
 
int main() {
    int action;

    do {
        scanf("%d", &action);
        
        switch (action)
        {
            case INSERT_MANY_TO_LIST:
                
            case INSERT_TO_SPECIFIC_INDEX:
            case PRINT_LIST:
            case PRINT_LIST_LENGTH:
            case PRINT_SPECIFIC_INDEX:
            case PRINT_NUM_OF_CHARS:
            case HOW_MANY_TIMES_STR_IN_LIST:
            case REMOVE_STR_FROM_LIST:
            case REMOVE_SPECIFIC_INDEX:
            case INVERT_LIST:
            case DELETE_LIST:
            case SORT_LEXI:
            case CHECK_SORTED_LEXI:
            case EXIT:
                return 0;
                break;        
            default:
                print("ERROR: incorrect input!");
        }
    } while (action != 0);

}