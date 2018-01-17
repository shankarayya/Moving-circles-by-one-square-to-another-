
//C++ program to implement a student database using inheritance

#include<stdio.h>
#include<iostream>
#include<string>
#include<limits>
//#include<conio.h>

using namespace std;

void pause()
{
     std::cout<<"Press Enter to continue....";
     std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}
//Creating a class with name student
class student
{
             protected:
             int roll_no;
  char name[40];
             char dept_name[40];
             char college[40];
             char dob[12];
             
             public:
             void get_input();
             void print_data();

};

//This function is used to input basic student information
void student::get_input()
{
     cout<<"\nEnter roll-no:";
     cin>>roll_no;
     cout<<"\nEnter name:";
     cin.ignore();
     cin.getline(name,100);
     cout<<"\nEnter department name:";
     cin.getline(dept_name,20);
     cout<<"\nEnter college name:";
     cin.getline(college,20);
     cout<<"\nEnter date of birth of this student(in DD/MM/YY format):";
     cin.getline(dob,12);
}

//This function is used to display basic student information
void student::print_data()
{
     cout<<"\n\nRoll:"<<roll_no;
     cout<<"\n\nName:"<<name;
     cout<<"\n\nDate of birth:"<<dob;
     cout<<"\n\nDepartment:"<<dept_name;
     cout<<"\n\nCollege:"<<college;
}

//Creating an class with name exam
class exam:virtual public student
{
      protected:
      int marks[5];
      
      public:
      void get_marks();
      void print_marks();
};

//This function is used to input marks of six subjects
void exam::get_marks()
{
     cout<<"\nEnter Marks\n-------------------\n";
     for(int i=0;i<6;i++)
     {
             while(true)
             {
                   cout<<"\nSubject"<<i+1<<":";
                        cin>>marks[i];
                        if(marks[i]>=0&&marks[i]<=100)//Checking validity of marks
                        break;
                        cout<<"Invalid marks given!!Enter proper marks..\n";
             }
     }
}

//This function is used to display marks of six subjects
void exam::print_marks()
{
     cout<<"\n\nMarks obtained in theory\n---------------------------\n";
     for(int i=0;i<6;i++)
     cout<<"Subject"<<i+1<<": "<<marks[i]<<"\n";

}
//Creating a class with name sports
class sports:virtual public student
{
      protected:
      char p_g;
      
      public:
      void get_grade();
      void print_grade();

};

//This function is used to input performance grade of a student
void sports::get_grade()
{
     while(true)
     {
           cout<<"\nEnter performance grade in sports for this student(A/B/C/D):";
           cin>>p_g;
           if(p_g=='A'||p_g=='B'||p_g=='C'||p_g=='D')
           break;
           cout<<"\nInvalid grade entered!!!";
     }

}

//This function is used to display performance grade of a student
void sports::print_grade()
{
     cout<<"\n\nPerformance grade in sports:"<<p_g;
}

//Creating a class with name result
class result:public exam,public sports
{
      private:
      int grand_total;

      public:
      void get_info();
      void display();
};

//This function is used to get all the information(basic, performance in exam and sports) of a student
void result::get_info()
{
     get_input();
     get_marks();
     get_grade();
}

//This function is used to display all the information of a student along with his or her result
void result::display()
{
     grand_total=0;
     for(int i=0;i<6;i++)
     grand_total+=marks[i];
     if(p_g=='A')
     grand_total+=50;
     if(p_g=='B')
     grand_total+=40;
     if(p_g=='C')
     grand_total+=30;
     if(p_g=='D')
     grand_total+=20;
     print_data();
     print_marks();
     print_grade();
     cout<<"\n\nAll total marks of "<<name<<":"<<grand_total<<"\n";
}

int main()
{
        
   //student s;     
		int num,i;
          while(true)
          {
                     cout<<"Enter number of students:";
                     cin>>num;
                     if(num>0)//Checking validity of number of students
                     break;
                     cout<<"Invalid number given!!\n";
          }
          result *stu=new result[num];//Dynamically allocating number of instances
          for(i=0;i<num;i++)
          {
                            cout<<"\n\nEnter record for student no:"<<i+1<<"\n\n-------------------------\n-------------------------";
                            stu[i].get_info();

          }
          cout<<"\n\nDisplaying results of students \n--------------------------------------------------------\n";
          //Printing all the student's information
          for(i=0;i<num;i++)
          {
                            cout<<"\n\n\nRecord for student no:"<<i+1<<"\n\n------------------------\n------------------------";
                            stu[i].display();
          }
          cout<<"\n";
          delete[]stu;
          return 0;
          

}

 