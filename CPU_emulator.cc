#include <iostream>
#include <cstring>
#include <map>
using std::cout;
using std::endl;
class Mem {
private:
   int m_MemSizeBytes;
   std::map<int, int[3]> Stick;
public:
   Mem(int MemSize): m_MemSizeBytes(MemSize) {
      for (int i = 0; i <= MemSize; i++) {
         int _[3] = {};
         memcpy(Stick[i], _, sizeof(int)*3);
      }
   };

   int* operator[](int inst) {
      return Stick[inst];
   };
};

namespace Cpu {
   enum Mnemonic {
      Mov = 0xaa1,
      Add = 0xaa2,
      Sub = 0xaa3,
      Mul = 0xaa4,
      Div = 0xaa5,
      Int = 0xaa6,
   };

   enum Register {
      eax = 0xbb1,
      ebx = 0xbb2,
      ecx = 0xbb3,
      edx = 0xbb4,
      esi = 0xbb5,
      esp = 0xbb6,
   };


};

int main() {
   Mem mem(5);
   mem[0] = { Cpu::Mnemonic::Mov, Cpu::Register::eax, Cpu::Register::ebx };
   cout << *mem[1] << endl;
}
