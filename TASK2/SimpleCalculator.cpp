#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Calculator{
    public:
    double Add(vector<double> nums){
        double res=0;
        for(const auto& num:nums){
            res+=num;
        }
        return res;
    }
   double Multiplication(vector<double> nums){
        long long res=1;
        for(const auto& num:nums){
            res*=num;

        }
        return res;
    }
    double subtract(vector<double> nums){
        long long res=0;
        for(const auto& num: nums){
            res+=num;
        }
        return res;
    }
    double divide(vector<double> nums){
        double res=nums[0];
        for(int i=1;i<nums.size();i++){
            res/=nums[i];
        }
        return res;
    }

};
int main(){
    Calculator c1;
    char choice;
    int n,num;
    string response;
    vector<double> input;
    cout << "welcome to Basic calculator" << endl;
    do
    {
        cout<<"Enter you choice (+ - * /) : ";
        cin>>choice;
        cout<<"Enter how many numbers you are going to enter :  ";
        cin>>n;
        cout<<"Enter Numbers :  ";
        for(int i=0;i<n;i++){
            cin>>num;
            input.push_back(num);
        }
        switch (choice){
            case '+':
            cout<<"Additions is "<<c1.Add(input)<<endl;
            break;
            case '-':
            cout<<"Subtraction is "<<c1.subtract(input)<<endl;
            break;
            case '*':
            cout<<"Multiplicaton is "<<c1.Multiplication(input)<<endl;
            break;
            case '/':
            cout<<"Divison is "<<c1.divide(input)<<endl;
            break;
            default:
            cout<<"Invalid Operation";
        }
        cout << "Do you want to continue using? (yes/no): ";
        cin >> response;
    } while (response == "yes");
}
