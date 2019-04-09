#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <iterator>

using namespace std;
int coNumAll=0;
int NUM[4];

void combinations(const string& s, vector<int>& pos, int n);
void PermGenerator(int n, int k,string numSt);
void CalculationFor42game(string dS[],int numA[]);
void allLexicographicRecur (char *str, char* data,int last, int index);
void allLexicographic(char *str);
int compare (const void * a, const void * b);
void printAllKLengthRec(char set[], string prefix,int n, int k, int numA2[]);
void printAllKLength(char set[], int k,int n, int numA2[]);
int caseCalc(char a,int a1,int a2);

int main()
{
    string inNum;
    cout<<"Number is : ";
    cin>>inNum;
    string s2 = inNum;
    do {
        // cout << s2 << endl;
        PermGenerator(4, 3,s2);
    } while (next_permutation(s2.begin(), s2.end()));

    if(coNumAll == 0)
        cout << "No Answer \n";
    return 0;
}

void PermGenerator(int n, int k, string numSt){
    int n2 = numSt.length();
    char char_array[n2 + 1];
    int numA[n2];
    string sA2;
    strcpy(char_array, numSt.c_str());

    for (int i = 0; i < n; i++){
        sA2= char_array[i];
        numA[i]= stoi(sA2);
        NUM[i]=numA[i];
    }
    char set1[] = {'+', '-','*','/'};
    printAllKLength(set1, k, n, NUM);
}

void CalculationFor42game(string dS2[],int numA2[]){
    char o,o2;
    char char_array[1];
    int numAll=0,num2=0,numAll2=0,num22=0;
    int numAA=0,numBB=0,numCC=0,numDD=0,numAB=0,numCD=0,sNumAB=0,sNumCD=0;

    //Case1 ((AxB)xC)xD =1
    for (int aL = 0; aL < 3; aL++) {

        strcpy(char_array, dS2[aL].c_str());
        o = char_array[0];

        if(aL == 0) {
            numAll = numA2[0];
            num2 = numA2[1];
            numAll = caseCalc(o,numAll,num2);
        }
        if(aL == 1) {
            num2 = numA2[2];
            numAll = caseCalc(o,numAll,num2);
        }
        if(aL == 2) {
            num2 = numA2[3];
            numAll = caseCalc(o,numAll,num2);
        }
    }
    if(numAll == 24){
        coNumAll++;
        cout <<"Case "<<coNumAll<<": ";
        cout <<"[("<<numA2[0]<<"";
        cout <<dS2[0];
        cout <<""<<numA2[1]<<")";
        cout <<dS2[1];
        cout <<""<<numA2[2]<<"]";
        cout <<dS2[2];
        cout <<""<<numA2[3]<<"";
        cout <<" = " << numAll;
        cout <<"\n";
    }

    //Case2 (AxB)x(CxD) =1
    for (int aL2 = 0; aL2 < 3; aL2++) {
        strcpy(char_array, dS2[aL2].c_str());
        o2 = char_array[0];

        // cout <<"(("<<o2<<"))";

        if(aL2 == 0) {
            numAA = numA2[0];
            numBB = numA2[1];
            numAB = caseCalc(o2,numAA,numBB);
        }
        if(aL2 == 1) {
            numCC = numA2[2];
            numDD = numA2[3];
            numCD = caseCalc(o2,numCC,numDD);
        }
        if(aL2 == 2) {

            numAll2 = caseCalc(o2,numAB,numCD);
        }

    }
    if(numAll2 == 24){
        coNumAll++;
        cout <<"Case "<<coNumAll<<": ";
        cout <<"("<<numA2[0]<<"";
        cout <<dS2[0];
        cout <<""<<numA2[1]<<")";
        cout <<dS2[2];
        cout <<"("<<numA2[2]<<"";
        cout <<dS2[1];
        cout <<""<<numA2[3]<<")";
        cout <<" = " << numAll2;
        cout <<"\n";
    }
}

int caseCalc(char a,int a1,int a2){
    int numAll=0;

    switch (a) {
        case '+':
            numAll = a1 + a2;
            break;
        case '-':
            if(a1 < a2){
                numAll=999; a2=999;}
            else{
                numAll = a1 - a2;}
            break;
        case '*':
            numAll = a1 * a2;
            break;
        case '/':
            if(a1 < a2){
                if(a1 != 0){
                    if((a2%a1)== 0)
                        numAll = a2 /a1;
                    else
                        numAll=999;a2=999;
                }else
                    numAll=999;a2=999;
            }
            else{
                if(a2 != 0){
                    if((a1%a2)== 0)
                        numAll = a1/a2;
                    else
                        numAll=999;a2=999;
                }else
                    numAll=999;a2=999;
            }

            break;
        default:
            // operator is doesn't match any case constant (+, -, *, /)
            cout << "Error! operator is not correct";
            break;
    }
    return numAll;
}

void combinations(const string& s, vector<int>& pos, int n) {
    if (n == s.size()) {
        for (int i = 0 ; i != n ; i++) {
            cout << s[pos[i]];
        }
        cout << endl;
        return;
    }
    for (int i = 0 ; i != s.size(); i++) {
        pos[n] = i;
        combinations(s, pos, n+1);
    }
}

void allLexicographicRecur (char *str, char* data, int last, int index){    int i, len = strlen(str);

    // One by one fix all characters at
    // the given index and recur for
    // the/ subsequent indexes
    for ( i = 0; i < len; i++ )
    {
        // Fix the ith character at index
        // and if this is not the last
        // index then recursively call
        // for higher indexes

        data[index] = str[i] ;

        // If this is the last index then
        // print the string stored in
        // data[]
        if (index == last)
            cout << data << endl;
        else // Recur for higher indexes
            allLexicographicRecur (str, data, last, index+1);
    }
}

void allLexicographic(char *str){
    int len = strlen (str) ;

    // Create a temp array that will
    // be used by allLexicographicRecur()
    char *data = (char *) malloc (sizeof(char) * (len + 1)) ;
    data[len] = '\0';

    // Sort the input string so that
    // we get all output strings in
    // lexicographically sorted order
    qsort(str, len, sizeof(char), compare);

    // Now print all permutaions
    allLexicographicRecur (str, data, len-1, 0);

    // Free data to avoid memory leak
    free(data);
}

int compare (const void * a, const void * b){
    return ( *(char *)a - *(char *)b );
}

void printAllKLengthRec(char set[], string prefix, int n, int k,int numA2[]){

    if (k == 0)
    {
        int n2 = prefix.length();
        char char_array[n2 + 1];
        string numA[n2];
        string sA2;
        strcpy(char_array, prefix.c_str());

        for (int i = 0; i < 3; i++){
            sA2= char_array[i];
            numA[i]= sA2;

        }

        CalculationFor42game(numA,NUM);

        return;
    }

    for (int j = 0; j < n; j++)
    {
        string newPrefix;
        newPrefix = prefix + set[j];

        // k is decreased, because
        // we have added a new character
        printAllKLengthRec(set, newPrefix, n, k - 1,numA2);
    }
}

void printAllKLength(char set[], int k,int n, int numA2[]){
    printAllKLengthRec(set, "", n, k,numA2);
}



