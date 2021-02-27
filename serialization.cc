#include <cstring>
#include <iostream>
#include <fstream>
struct serializable {
   virtual void operator<<(std::fstream&) = 0;
   virtual void operator>>(std::fstream&) const = 0;
};

struct Vector2 : serializable {
   int x, y;
   Vector2(int _x, int _y) : x(_x), y(_y){};
   void operator<<(std::fstream& fs) override {
      fs >> this->x;
      fs >> this->y;
   };
   
   void operator>>(std::fstream& fs) const override {
      fs << this->x;
      fs << this->y;
   };
};

int main() {
   std::fstream bin("binfile.dat");
   Vector2 vect(1, 2);
   if(!bin.is_open()) {
      std::cerr << "Error: could not open file\n";
      return 1;
   };

   vect >> bin;
   vect << bin;

   bin.close();
   return 0;
}
