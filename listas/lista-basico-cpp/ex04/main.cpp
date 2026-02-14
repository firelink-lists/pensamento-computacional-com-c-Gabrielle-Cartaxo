/**
 * @exercise Lista Básico C++ - Exercício 4
 * @title Template e Shared Pointer
 * @description Crie uma template de função `trocar` que receba dois parâmetros por referência e troque seus valores. No `main`, crie dois `shared_ptr` para diferentes tipos (ex: `int` e `double`), use a função template para trocar os valores apontados pelos shared_ptr, exiba os valores antes e depois da troca, e mostre a contagem de referências.
 * @input stdin
 * @output stdout
 * @timeout 1000
 * @test name="Troca int" input="5 10" expected="Antes: 5 10\nDepois: 10 5\nRefs: 1 1"
 * @test name="Troca double" input="3.14 2.71" expected="Antes: 3.14 2.71\nDepois: 2.71 3.14\nRefs: 1 1"
 */

#include <iostream>
#include <memory>

using namespace std;

// TODO: Crie o template de função trocar

template<typename T>
void trocar(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {

    // pegar dois numeros do usuário e depois definir se é int ou double
    string input1, input2;
    cin >> input1 >> input2;
    int int1 = 0;
    int int2 = 0;
    double double1 = 0.0;
    double double2 = 0.0;

    // Verificar se os inputs são int ou double
    bool isInt = true;
    for (char c : input1) {
        if (!isdigit(c) && c != '-') {
            isInt = false;
            break;
        }
    }
    for (char c : input2) {
        if (!isdigit(c) && c != '-' && c != '.') {
            isInt = false;
            break;
        }
    }
    if (isInt) {
        int int1 = stoi(input1);
        int int2 = stoi(input2);
    
        // TODO: Crie shared_ptr para int
        shared_ptr<int> ptrInt1 = make_shared<int>(int1);
        shared_ptr<int> ptrInt2 = make_shared<int>(int2);

        // TODO: Exiba valores antes da troca
        cout << "Antes: " << *ptrInt1 << " " << *ptrInt2 << endl;
    
        // TODO: Troque os valores
        trocar(*ptrInt1, *ptrInt2);
    
        // TODO: Exiba valores depois da troca
        cout << "Depois: " << *ptrInt1 << " " << *ptrInt2 << endl;
    
        // TODO: Mostre contagem de referências
        cout << "Refs: " << ptrInt1.use_count() << " " << ptrInt2.use_count() << endl;
    }


    if (!isInt) {
        double double1 = stod(input1);
        double double2 = stod(input2);

        // TODO: Crie shared_ptr para double
        shared_ptr<double> ptrDouble1 = make_shared<double>(double1);
        shared_ptr<double> ptrDouble2 = make_shared<double>(double2);
        
        // TODO: Exiba valores antes da troca - DOUBLE
        cout << "Antes: " << *ptrDouble1 << " " << *ptrDouble2 << endl;
        
        // TODO: Troque os valores - DOUBLE
        trocar(*ptrDouble1, *ptrDouble2);
        
        // TODO: Exiba valores depois da troca- DOUBLE
        cout << "Depois: " << *ptrDouble1 << " " << *ptrDouble2 << endl;
        
        // TODO: Mostre contagem de referências - DOUBLE
        cout << "Refs: " << ptrDouble1.use_count() << " " << ptrDouble2.use_count() << endl;}
        
    return 0;
}
