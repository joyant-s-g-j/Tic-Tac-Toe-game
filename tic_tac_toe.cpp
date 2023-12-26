#include<bits/stdc++.h>
using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6',},{'7','8','9'}};
int row;
int column;
char command='X';
bool draw =false;;
string p1=" ";
string p2=" ";

void fun_1()
{
    //structure
    cout<<"     |    |     "<<endl;
    cout<<"   "<<space[0][0]<<" |  "<<space[0][1]<<" | "<<space[0][2]<<" "<<endl;
    cout<<"_____|____|_____"<<endl;
    cout<<"     |    |     "<<endl;
    cout<<"   "<<space[1][0]<<" |  "<<space[1][1]<<" | "<<space[1][2]<<" "<<endl;
    cout<<"_____|____|_____"<<endl;
    cout<<"     |    |     "<<endl;
    cout<<"   "<<space[2][0]<<" |  "<<space[2][1]<<" | "<<space[2][2]<<" "<<endl;
    cout<<"     |    |     "<<endl;
}
void fun_2()
{
    int digit;
    if (command=='X')
    {
        cout<<p1<<" Please enter a value: ";
        cin>>digit;
        
    }
    if (command=='O')
    {
        cout<<p2<<" Please enter a value: ";
        cin>>digit;
    }
    if(digit==1)
    {
        row=0;
        column=0;
    }
    else if(digit==2)
    {
        row=0;
        column=1;
    }
    else if(digit==3)
    {
        row=0;
        column=2;
    }
    else if(digit==4)
    {
        row=1;
        column=0;
    }
    else if(digit==5)
    {
        row=1;
        column=1;
    }
    else if(digit==6)
    {
        row=1;
        column=2;
    }
    else if(digit==7)
    {
        row=2;
        column=0;
    }
    else if(digit==8)
    {
        row=2;
        column=1;
    }
    else if(digit==9)
    {
        row=2;
        column=2;
    }
    else if(digit>1 || digit<9)
    {
        cout<<"Invalid Digit!!!"<<endl;
        fun_2();
        return;
    }
    if(command=='X' && space[row][column] !='X' && space[row][column] !='O')
    {
        space[row][column]='X';
        command='O';
    }
    else if(command=='O' && space[row][column] !='X' && space[row][column])
    {
        space[row][column]='O';
        command='X';
    }
    else
    {
        cout<<"There is no empty space"<<endl;
        return;
        fun_2();
    }
    
    fun_1();
}
bool fun_3()
{
    for(int i=0;i<3;i++)
    {
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        return true;
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
    return true;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j]!='X' && space[i][j]!='O')
            {
                return false;
            }
        }
    }
    draw = true;
    return true;
    
}
int main()
{
    cout<<"Enter the name of the first player name: ";
    getline(cin, p1);
    cout<<"Enter the name of the second player name: ";
    getline(cin, p2);
    cout<<p1<<" is player one so he/she will play first"<<endl;
    cout<<p2<<" is player two so he/she will play second"<<endl;
    
    while(!fun_3())
    {
        fun_1();
        fun_2();
    }
    if(command=='X' && draw == false)
    {
        cout<<p2<<" wins the game"<<endl;
    }
    else if(command=='O' && draw == false)
    {
        cout<<p1<<" wins the game"<<endl;
    }
    else
    {
        cout<<"The game is draw!!!"<<endl;
    }

    return 0;
}