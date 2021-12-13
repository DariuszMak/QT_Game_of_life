#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <fstream>
//#include <iostream>
using namespace std;

#include <QTime>//potrzebne do określenia losowości
#include <QMainWindow>
#include <string>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QString>
#include <QDialog>
#include <QTimer>

#include <QCloseEvent>
#include "lcd_state_boolean_table.h"
#include "ui_mainwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    ConwayAlg * Algorithm;//wskaźnik na obiekt klasy ConwayAlg

    int Table_widget_cell_size;

    int NumberOfColumns;
    int NumberOfRows;

    bool IsRunning;//zmienna wyznaczająca, czy symulacja trwa, czy nie
    bool Changed;//zmienna przechowująca informację, czy coś się na ekranie zmieniło
    QTimer Timer;//timer wykorzystany do animacji
//    QTimer TimerController;//timer wykorzystany do kontroli szybkości odświeżania się algorytmu

//    int MilisecondsPerFrame;//zmienna przechowująca ilość klatek

    int MinSizeSquare;//zmienna przechowująca najmniejszą dopuszczalną wartość rozmiaru pojedynczego kwadracika w tabeli w pikselach

    QString TitleProj;//zmienna typu string przechowująca tytuł całego projektu

    QColorDialog ChooseAliveColor;//okno dialogowe wyboru koloru dla żywych kwadracików
    QColorDialog ChooseDeadColor;//okno dialogowe wyboru koloru dla martwych kwadracików
    QColor AliveColor;//zmienna przechowująca kolor żywych kwadracików
    QColor DeadColor;//zmienna przechowująca kolor martwych kwadracików

    void SetInitialValues();//metoda ustawiająca wszystkie niezbędne wartości początkowe (rozmiar, ilość kolumn i wierszy na interfejsie, domyślne kolory)

    void ChangeSet();//metoda zmieniająca tytuł okna oraz wartość zmiennej changed

    void resizeEvent(QResizeEvent *event);

    void closeEvent(QCloseEvent * event);//specjalna metoda do przedefiniwania działań przy zamykaniu programu

private slots:
    void RowsChanged(int);//utworzenie odpowiedniej wielkości wierszy tabeli na podstawie przyjętej wartości
    void ColumnsChanged(int);//utworzenie odpowiedniej wielkości kolumn tabeli na podstawie przyjętej
    void SwitchField(int, int, bool);//funkcja ustawiająca w tabeli odpowiedni kwadracik w zależności od przyjętej wartości logicznej
    //void UpadeScreen();//funkcja aktualizująca stan ekranu z algorytmem
    void ClearScreen();//funkcja czyszcząca ekran i dane w algorytmie i na ekranie jednocześnie zatrzymuje symulację, ponieważ nie ma żywych pól w tabeli
    void ResizeField(int);//funkcja przyjmująca rozmiar pojedynczego pola na ekranie
    void TidyUpScreen();//funkcja dobierająca właściwości w oknie tak, aby kompozycja była spójna
    //void TimerControllerTimeout();//akcja reagująca na przepełnienie się timera kontrolującego przebieg animacji


    void on_actionOd_wie_triggered();

    void on_actionKolor_ywych_kom_rek_triggered();

    void on_actionKo_lor_martwych_kom_rek_triggered();

signals:

    void StatusAsk();//zapytanie algorytmu o ilość żywych kokórek i iteracji
    void ScreenAsk();//zapytanie o wszystkie wartości prawdziwe w tablicy roboczej algorytmu
    void ClearAlg(); //zerowanie zawartości tablicy roboczej algorytmu
    void TidyUp();//sygnał porządkujący właściowści ona programu w celu uzyskania maksymalnej spójności
    void CloseOtherWindows();//sygnał zamknięcia innych okien
};

#endif // MAINWINDOW_H
