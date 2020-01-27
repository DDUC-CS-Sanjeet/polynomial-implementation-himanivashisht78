#include<iostream>
using namespace std;

class Polynomial
{
    private:
        int * p;
        int degree;
    public:
        Polynomial(int degree = 1)
        { 
            p = new int[degree+1];
            this->degree = degree;
        }
        void get_input()
        {
            for(int i = 0; i <= degree; ++i)
            {
                cout << "Enter coefficient for x^" << i << ": ";
                cin >> p[i];
            }
        }
        void show_output()
        {
            for(int i = degree; i >=0; i--)
            {
                
                if(i==0)
                {
                    cout << p[i] << "x^" << i<<" ";
				}
				else
				{
					cout << p[i] << "x^" << i<<" + ";
				}
            }
            cout << "\n";
        }
        Polynomial operator +(Polynomial& poly)
        {
            Polynomial new_p;
            int max_degree = poly.degree > degree ? poly.degree : degree;
            new_p.degree = max_degree;
            new_p.p = new int[max_degree+1]{0};
            for(int i = 0; i <= max_degree; ++i)
            {
                if(i <= degree) new_p.p[i] += p[i];
                if(i <= poly.degree) new_p.p[i] += poly.p[i];
            }
            return new_p;
        }
        Polynomial operator -(Polynomial& poly)
        {
            Polynomial new_p;
            int max_degree = poly.degree > degree ? poly.degree : degree;
            new_p.degree = max_degree;
            new_p.p = new int[max_degree+1]{0};
            for(int i = 0; i <= max_degree; ++i)
            {
                if(i <= degree) new_p.p[i] += p[i];
                if(i <= poly.degree) new_p.p[i] -= poly.p[i];
            }
            return new_p;
        }
};

int main()
{
	int degfirst , degsecond;
	cout<<" Enter the degree first :  ";
	cin>>degfirst;
	cout<<" Enter the degree second : ";
	cin>>degsecond;
    Polynomial firstPolynomial(degfirst);
    firstPolynomial.get_input();
    firstPolynomial.show_output();
    Polynomial secondPolynomial(degsecond);
    secondPolynomial.get_input();
    secondPolynomial.show_output();
    Polynomial thirdPolynomial = firstPolynomial + secondPolynomial;
    cout<<"Adding first and second Polynomial::::   Results into::::    ";
    thirdPolynomial.show_output();
    Polynomial fourthPolynomial = firstPolynomial - secondPolynomial;
    cout<<"Subracting second Polynomial from first:::  Results into:::   ";
    fourthPolynomial.show_output();
    return 0;
}
