////////////////////
//      Liam Floyd
//      CS201L
//      Lab #9
////////////////////
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("inputPizza.txt");
    ofstream fout("outputPizza.txt");
    //Set input and output

    int cnt = 1;
    //Make counter to display menu number
    while(fin.good()){
        int itemsNum;
        fin >> itemsNum;
        //Read into the number of items in a menu
        if (itemsNum == 0){
            break;
            //Break if the end of the file is reached, rather than operating on zero
        }

        double bestVal = 100.0;
        int bestPizza = 0;

        for(int i = 0; i < itemsNum; i++){
            int tempDia, tempCost;

            fin >> tempDia >> tempCost;

            double rad = tempDia / 2;
            double area = (rad * rad) * 3.1415926535897;
            double val = tempCost / area;
            //Can be simplified, but figure out the value of the current pizza to compare it

            if (val < bestVal){
                bestVal = val;
                bestPizza = tempDia;
                //Update bestVal and Pizza if current Pizza is a better value
            }
        }
        fout << "Menu " << cnt << ": " << bestPizza << endl;
        cnt++;
    }
    return 0;
}
