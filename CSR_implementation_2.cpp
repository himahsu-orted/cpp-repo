#include <bits/stdc++.h>
using namespace std;

typedef struct Snode_branch
{
    struct Snode_branch *Snode_branch_next;
    struct Cnode *Snode_to_Cnode;
} * SB;

typedef struct Cnode_branch
{
    struct Cnode_branch *Cnode_branch_next;
    struct Snode *Cnode_to_Snode;
} * CB;

typedef struct Snode
{
    int studentName;
    struct Snode *nextStudent;
    struct Snode_branch *sBranch;

} * SL;

typedef struct Cnode
{
    char courseName;
    struct Cnode *nextCourse;
    struct Cnode_branch *cBranch;
} * CL;
void makeList(SL S, CL C)
{
    SL S_cur, S_end = S;
    CL C_cur, C_end = C;

    int iVal;
    ;
    char cVal;
    cin >> iVal >> cVal;

    SB SB_cur;
    CB CB_cur;

    while (iVal > -1 && cVal != '#')
    {
        SB_cur = new (struct Snode_branch);
        CB_cur = new (struct Cnode_branch);

        SB_cur->Snode_branch_next = NULL;
        CB_cur->Cnode_branch_next = NULL;

        SL FIND = S;
        while (FIND != NULL)
        {
            if (FIND->studentName == iVal)
                break;

            FIND = FIND->nextStudent;
        }
        if (FIND == NULL)
        {
            S_cur = new (struct Snode);
            S_cur->studentName = iVal;
            S_cur->nextStudent = NULL;
            S_cur->sBranch = SB_cur;
            S_end->nextStudent = S_cur;
            S_end = S_cur;

            CB_cur->Cnode_to_Snode = S_cur;
        }
        else
        {
            SB SB_temp = FIND->sBranch;
            while (SB_temp != NULL)
            {
                if (SB_temp->Snode_branch_next == NULL)
                    break;

                SB_temp = SB_temp->Snode_branch_next;
            }

            SB_temp->Snode_branch_next = SB_cur;

            CB_cur->Cnode_to_Snode = FIND;
        }
        CL TEMP = C;
        while (TEMP != NULL)
        {
            if (TEMP->courseName == cVal)
                break;

            TEMP = TEMP->nextCourse;
        }
        if (TEMP == NULL)
        {
            C_cur = new (struct Cnode);
            C_cur->courseName = cVal;
            C_cur->nextCourse = NULL;
            C_cur->cBranch = CB_cur;
            C_end->nextCourse = C_cur;
            C_end = C_cur;

            SB_cur->Snode_to_Cnode = C_cur;
        }
        else
        {
            CB R_temp = TEMP->cBranch;
            while (R_temp != NULL)
            {
                if (R_temp->Cnode_branch_next == NULL)
                    break;

                R_temp = R_temp->Cnode_branch_next;
            }
            R_temp->Cnode_branch_next = CB_cur;

            SB_cur->Snode_to_Cnode = TEMP;
        }
        cin >> iVal >> cVal;
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

    SL S;
    CL C;
    SB Sbranch;
    CB Cbranch;
    int iVal;
    char ch, cVal;
    cin >> iVal;
    cin >> cVal;
    S = new (struct Snode);
    C = new (struct Cnode);
    Sbranch = new (struct Snode_branch);
    Cbranch = new (struct Cnode_branch);

    S->studentName = iVal;
    C->courseName = cVal;

    S->nextStudent = NULL;
    C->nextCourse = NULL;

    Sbranch->Snode_to_Cnode = C;
    Cbranch->Cnode_to_Snode = S;

    Sbranch->Snode_branch_next = NULL;
    Cbranch->Cnode_branch_next = NULL;

    S->sBranch = Sbranch;
    C->cBranch = Cbranch;

    makeList(S, C);
}