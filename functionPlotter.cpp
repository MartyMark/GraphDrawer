#include "functionPlotter.h"

double FunctionPlotter::calculate(double x){
    this->funcString = adaptFunction(currentFunction->getName());
    this->disFunc = dismantleFunction(funcString);

    vector<QString> solution = replaceX(x);
    solution = solvePows(solution);
    solution = solveMultiplication(solution);
    return solveAddition(solution);
}

//Macht aus 2x -> 2*x
QString FunctionPlotter::adaptFunction(QString func){
    QString temp = "";

    func += Marker::END;
    QRegExp regDec("[0-9]");

    for(int i = 0; i < func.size(); i++) {
        QChar curr = func.at(i);

        if(curr == Marker::END){
            break;
        }

        QChar next = func.at(i+1);

        if(regDec.exactMatch(curr) && next == 'x'){
            temp = temp + curr + '*';
        }else{
            temp = temp + curr;
        }
    }
    return temp;
}

//Die Funktion wird hier in seine Einzelteile zerlegt.
//Bsp: 22x^3+24 -> 22, x, ^, 3, 24 -> Das Plus muss nicht übernommen werden.
vector<QString> FunctionPlotter::dismantleFunction(QString func){
    func += Marker::END;

    vector<QString> disFunc;
    QString temp = "";

    QRegExp regDec("[x.0-9-]");
    QRegExp regOpe("[-+*^]"); //Das Minus muss vorne stehen!!!
    QRegExp regMH("[*^]");
    for(int i = 0; i < func.size(); i++) {
        QChar curr = func.at(i);

        if(curr == Marker::END){
            break;
        }

        QChar next = func.at(i+1);

       if(regDec.exactMatch(curr)){
           temp = temp + curr;
       }

       if(regMH.exactMatch(curr)){
           disFunc.push_back(curr);
       }

       if(regOpe.exactMatch(next) || next == Marker::END){
           disFunc.push_back(temp);
           temp = "";
       }
    }
    disFunc.push_back(QString(Marker::END));
    return disFunc;
}

vector<QString> FunctionPlotter::replaceX(double value){
    vector<QString> func(disFunc);

    for(vector<QString>::size_type i = 0; i != func.size(); i++) {
        func.at(i).replace('x', QString::number(value));
    }
    return func;
}

//Macht aus 2*2^2 -> 2*4
vector<QString> FunctionPlotter::solvePows(vector<QString> func){
    vector<QString> solveFunc;

    for(vector<QString>::size_type i = 0; i != func.size(); i++) {
        QString curr = func.at(i);

        if(curr == Marker::END){
            break;
        }

        QString next = func.at(i+1);

        if(next != Marker::END && next == "^"){
            QString third = func.at(i+2);
            QString result;

            if(curr.toDouble() < 0){
                result = result + '-';
            }

            solveFunc.push_back(result + QString::number(pow(curr.toDouble(), third.toDouble())));
            i += 2;
        }else{
            solveFunc.push_back(curr);
        }
    }
    solveFunc.push_back(QString(Marker::END));
    return solveFunc;
}

//Übernimmt die Multiplikations aufgaben.
//Eine für Divison habe ich noch nicht.
vector<QString> FunctionPlotter::solveMultiplication(vector<QString> func){
    vector<QString> solveMulti;

    for(vector<QString>::size_type i = 0; i != func.size(); i++) {
        QString curr = func.at(i);

        if(curr == Marker::END){
            break;
        }

        QString next = func.at(i+1);

        if(next != Marker::END && next == "*"){
            QString third = func.at(i+2);
            solveMulti.push_back(QString::number(curr.toDouble() * third.toDouble()));
            i += 2;
        }else{
            solveMulti.push_back(curr);
        }

    }
    return solveMulti;
}

//Diese Methode wird immer am Ende aufgerufen.
//Der Übergebe Vector sieht meist immer so aus : 2,3,-4,6
double FunctionPlotter::solveAddition(vector<QString> func){
    double solution = 0;

    for(vector<QString>::size_type i = 0; i != func.size(); i++) {
        solution = solution + func.at(i).toDouble();
    }
    return solution;
}

Function* FunctionPlotter::getCurrentFunction(){
    return currentFunction;
}

void FunctionPlotter::setCurrentFunction(Function* function){
    this->currentFunction = function;
}

