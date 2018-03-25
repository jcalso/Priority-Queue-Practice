#include <iostream>
#include <queue>
#include <iomanip>

#include <string>
#include <vector>
using namespace std;

//Object used in PQ
class Person{
  public:
  int age;
  string name;
 // int goals;
  //int assists;
};

//Comparing Operations
class CompareLessAge {
  public:
  bool operator ()(Person &p1, Person &p2){
    return p1.age < p2.age;
  }
};
class CompareGreaterAge {
  public:
  bool operator ()(Person &p1, Person &p2){
    return p1.age > p2.age;
  }
};
class CompareNameWithMostVowels{
  private:
  string vowels = "aeiouAEIOU";
  public:
  bool operator ()(Person &p1, Person &p2){
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i< p1.name.length(); i++){
      for (int j = 0; j < vowels.length();j++){
        if(p1.name[i] == vowels[j]){
          count1++;
        }
      }
    }
    for(int i = 0; i< p2.name.length(); i++){
      for (int j = 0; j < vowels.length();j++){
        if(p2.name[i] == vowels[j]){
          count2++;
        }
      }
    }
    return count1 < count2;
  }
};
  

int main() {
  //Declare PQ using using elements of type person, with a vector conatiner of people, ordering them by the third argument, named 'pq'
  priority_queue< Person, vector<Person>, CompareLessAge> pq; 
  int size = 6;
  Person p[size] = {{89, "Charles"}, {24, "Bob"}, {30, "Andy"},{70, "Jonathan"}, {1, "Kishan"},{55, "AEioiu"}};
  for (int i = 0; i< size; ++i){
    pq.push(p[i]);
  }
  
  while (!pq.empty()){
    cout << pq.top().age << " ";
    pq.pop();
  }
  return 0;
}
