#include <bits/stdc++.h>
using namespace std;

typedef struct Snode
{
    struct Snode *Snode_to_Snode;
    int student_number;
    struct Rnode *Snode_to_Rnode;
} * SN;
typedef struct Cnode
{
    struct Cnode *Cnode_to_Cnode;
    char course_name;
    struct Rnode *Cnode_to_Rnode;
} * CN;
union u1
{
    struct Rnode *ver_Rnode;
    struct Snode *ver_Snode;
};
union u2
{
    struct Rnode *hor_Rnode;
    struct Cnode *hor_Cnode;
};
typedef struct Rnode
{
    union u1 *ver;
    union u2 *hor;
} * RN;
void makeList(SN S, CN C)
{
    SN S_cur, S_end;
    S_end = S;

    CN C_cur, C_end;
    C_end = C;

    RN R_cur;

    int n;
    char ch;
    cin >> n >> ch;

    while (n > -1 && ch != '#')
    {
        R_cur = new (struct Rnode);
        R_cur->ver = new (union u1);
        R_cur->hor = new (union u2);

        SN FIND=S;
        while(FIND!=NULL)
        {
            if(FIND->student_number==n)
            break;

            FIND=FIND->Snode_to_Snode;
        }
        if(FIND==NULL)
        {
            S_cur = new (struct Snode);
            S_cur->student_number = n;
            S_cur->Snode_to_Snode = NULL;
            S_cur->Snode_to_Rnode = R_cur;
            S_end->Snode_to_Snode = S_cur;
            S_end = S_cur;
        }
        else
        {
            RN R_temp = FIND->Snode_to_Rnode;
            while (R_temp != NULL)
            {
                if (R_temp->ver->ver_Rnode == NULL)
                    break;

                R_temp = R_temp->ver->ver_Rnode;
            }
            R_temp->ver->ver_Rnode = R_cur;
        }
        CN TEMP = C;
        while (TEMP != NULL)
        {
            if (TEMP->course_name == ch)
                break;

            TEMP = TEMP->Cnode_to_Cnode;
        }
        if (TEMP == NULL)
        {
            C_cur = new (struct Cnode);
            C_cur->course_name = ch;
            C_cur->Cnode_to_Cnode = NULL;
            C_cur->Cnode_to_Rnode = R_cur;
            C_end->Cnode_to_Cnode = C_cur;
            C_end = C_cur;
        }
        else
        {
            RN R_temp = TEMP->Cnode_to_Rnode;
            while (R_temp != NULL)
            {
                if (R_temp->hor->hor_Rnode == NULL)
                    break;

                R_temp = R_temp->hor->hor_Rnode;
            }
            R_temp->hor->hor_Rnode = R_cur;
        }
        cin >> n >> ch;
    }
    while (S != NULL)
    {
        RN RC = S->Snode_to_Rnode;
        while (RC != NULL)
        {
            if (RC->ver->ver_Rnode == NULL)
            {
                RC->ver->ver_Snode = S;
                break;
            }
            RC = RC->ver->ver_Rnode;
        }
        S = S->Snode_to_Snode;
    }
    while (C != NULL)
    {
        RN RC = C->Cnode_to_Rnode;
        while (RC != NULL)
        {
            if (RC->hor->hor_Rnode == NULL)
            {
                RC->hor->hor_Cnode = C;
                break;
            }
            RC = RC->hor->hor_Rnode;
        }
        C = C->Cnode_to_Cnode;
    }
}
bool charChecker(CN C, char ch)
{
    while (C != NULL)
    {
        if (ch == C->course_name)
            return true;

        C = C->Cnode_to_Cnode;
    }
    return false;
}
bool intChecker(SN S, int n)
{
    while (S != NULL)
    {
        if (S->student_number == n)
            return true;

        S = S->Snode_to_Snode;
    }
    return false;
}
int SSize(SN S)
{
    int i=0;
    while(S!=NULL)
    {
        i++;
        S=S->Snode_to_Snode;
    }
    return i;
}
void findByStudent(SN S, CN C, int n)
{
    SN S_temp = S;
    while (S_temp != NULL)
    {
        if (S_temp->student_number == n)
        {
            break;
        }

        S_temp = S_temp->Snode_to_Snode;
    }

    RN R_temp = S_temp->Snode_to_Rnode;

    while (R_temp != NULL)
    {

        RN R_hor = R_temp;

        while (R_hor != NULL)
        {
            if (charChecker(C, R_hor->hor->hor_Cnode->course_name))
            {
                cout << R_hor->hor->hor_Cnode->course_name<<" ";
                break;
            }
            R_hor = R_hor->hor->hor_Rnode;
        }
        if (R_temp->ver->ver_Snode->student_number == n)
            break;
        R_temp = R_temp->ver->ver_Rnode;
    }
}
void findByCourse(SN S, CN C, char ch)
{

    CN C_temp = C;
    while (C_temp != NULL)
    {
        if (C_temp->course_name == ch)
        {
            break;
        }

        C_temp = C_temp->Cnode_to_Cnode;
    }

    RN R_temp = C_temp->Cnode_to_Rnode;
    int size=SSize(S);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        arr[i]=size+1;
    }
    int i=0;
    while (R_temp != NULL)
    {

        RN R_ver = R_temp;
        while (R_ver != NULL)
        {
            if (intChecker(S, R_ver->ver->ver_Snode->student_number))
            {
                arr[i++]=R_ver->ver->ver_Snode->student_number;
                break;
            }
            R_ver = R_ver->ver->ver_Rnode;
        }
        if (R_temp->hor->hor_Cnode->course_name == ch)
            break;
        R_temp = R_temp->hor->hor_Rnode;
    }
    sort(arr, arr+size);
    for(int i=0;i<size;i++)
    {
        if(arr[i]<size)
        cout<<arr[i]<<" ";
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    SN S;
    CN C;
    RN R;

    int n;
    char ch;

    cin >> n;
    cin >> ch;

    S = new (struct Snode);
    C = new (struct Cnode);
    R = new (struct Rnode);

    S->student_number = n;
    C->course_name = ch;

    S->Snode_to_Rnode = R;
    C->Cnode_to_Rnode = R;

    S->Snode_to_Snode = NULL;
    C->Cnode_to_Cnode = NULL;

    R->ver = new (union u1);
    R->hor = new (union u2);

    R->hor->hor_Cnode = NULL;
    R->hor->hor_Rnode = NULL;
    R->ver->ver_Rnode = NULL;
    R->ver->ver_Snode = NULL;

    makeList(S, C);

    cin >> n;
    findByStudent(S, C, n);
    cout << endl;

    cin >> n;
    findByStudent(S, C, n);
    cout << endl;

    cin >> ch;
    findByCourse(S, C, ch);
    cout << endl;

    cin >> ch;
    findByCourse(S, C, ch);
}