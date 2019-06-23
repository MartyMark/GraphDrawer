#ifndef FUNCTION_H
#define FUNCTION_H

#include <QString>
#include <QByteArray>
#include <math.h>
#include <algorithm>
#include <list>
#include <QRegularExpression>
#include <vector>
#include <QObject>
#include "function.h"

using namespace std;

/**
 * @brief The FunctionPlotter class
 * @details This class calculates a Y-Value to a given X.
 * Therefore a Function has to be set.
 * After this step, the Calculate-Funtion can be executed,
 * which returns the Y-Value to a given X-Value.
 *
 * @author Marty Burghardt
 * @version 1.0
 * @date 11.01.19
 */
class FunctionPlotter : public QObject{
    Q_OBJECT

private:
    QString funcString;
    Function* currentFunction;

    /**
     * @details This vector of qstrings contains individual components of the Function-String.
     */
    vector<QString> disFunc;
    enum Marker {END = 'E'};

    /**
     * @details This method dismantled the function into his components.
     * @param funcString
     * @return vector<QString>
     */
    vector<QString> dismantleFunction(QString funcString);

    /**
     * @brief Adapt the Function-string
     * @details If the user entrered 2x -> this method will return 2*x
     * @param funcString
     * @return QString
     */
    QString adaptFunction(QString funcString);

    /**
     * @brief replaces the x with the given value
     * @param value
     * @return vector<QString>
     */
    vector<QString> replaceX(double value);

    /**
     * @brief solve the Pows of the given function
     * @param func
     * @return vector<QString>
     */
    vector<QString> solvePows(vector<QString> func);

    /**
     * @brief solve the multiplication.
     * @details this method solves multiplication. But now Pows. Therefore is the method "solvePows".
     * @param func
     * @return vector<QString>
     */
    vector<QString> solveMultiplication(vector<QString> func);

    /**
     * @brief solves addition-operations
     * @details solves addition and subtraction.<br>
     * This method need to be called last.
     *
     * @param func
     * @return double
     */
    double solveAddition(vector<QString> func);

public:
    FunctionPlotter(){}

    Function* getCurrentFunction();
    void setCurrentFunction(Function* function);

    ~FunctionPlotter(){
        delete currentFunction;
    }
public slots:

    /**
     * @brief calculates the y-value to a given x-value.
     * @param x
     * @return double y
     */
    double calculate(double x);
};

#endif // FUNCTION_H
