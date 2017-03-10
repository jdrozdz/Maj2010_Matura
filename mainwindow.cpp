#include "mainwindow.h"
#include "ui_mainwindow.h"

QList<QString> zadanie1;

int licznik = 0, pkt = 0, pkt_tmp = 0, zamek = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    zadanie1.append("pobranie pierwszego od dołu elementu.");
    zadanie1.append("usunięcie pierwszego od dołu elementu.");
    zadanie1.append("pobranie pierwszego od góry elementu.");

    QMessageBox::information(this, "Informacja", "Zdecyduj, które z podanych stwierdzeń są prawdziwe (zaznaczone pole), a które fałszywe (odznaczone pole).");
    ui->label->setText("Pojedyncza operacja wykonywana na stosie to");

    ui->checkBox->setText(zadanie1[0]);
    ui->checkBox_2->setText(zadanie1[1]);
    ui->checkBox_3->setText(zadanie1[2]);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton odpowiedz = QMessageBox::question(this, "", "Czy zakończyć działanie programu?", QMessageBox::Yes|QMessageBox::No);

    if(odpowiedz == QMessageBox::Yes){
        this->close();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(licznik == 0){
        (!ui->checkBox->isChecked()) ? pkt_tmp++ : 0;
        (!ui->checkBox_2->isChecked()) ? pkt_tmp++ : 0;
        (ui->checkBox_3->isChecked()) ? pkt_tmp++ : 0;
        licznik++;
        pkt = pkt_tmp;
    }

    if(licznik == 1 && zamek == 1){
        (!ui->checkBox->isChecked()) ? pkt_tmp++ : 0;
        (!ui->checkBox_2->isChecked()) ? pkt_tmp++ : 0;
        (ui->checkBox_3->isChecked()) ? pkt_tmp++ : 0;
        licznik++;
        pkt += pkt_tmp;
        zamek = 0;
    }

    QMessageBox::StandardButton odpowiedz = QMessageBox::question(this, "", QString("Brawo zdobyłeś %1 %2.\nW sumie masz %3 %4\nCzy kontynuwać?").arg(pkt_tmp).arg( pkt_tmp > 1 ? "punkty" : "punkt" ).arg(pkt).arg( pkt_tmp > 1 ? "punkty" : "punkt" ));
    pkt_tmp = 0;

    if(odpowiedz == QMessageBox::Yes){

        ui->checkBox->setChecked(false); ui->checkBox_2->setChecked(false); ui->checkBox_3->setChecked(false);

        // pytanie 2
        if(licznik == 1){
            QPixmap obrazek(":/algorytm1");
            ui->label->setPixmap(obrazek);
            // ui->label->setMask(obrazek.mask());

            ui->checkBox->setText("Algorytm znajduje NWW(a,b)");
            ui->checkBox_2->setText("Algorytm znajduje NWD(a,b)");
            ui->checkBox_3->setText("liczbę pierwszą większą od a i mniejszą od b.");
            zamek = 1;
        }

        if(licznik == 2){
            ui->label->setText("Liczba 1000<sub>16</sub> to: ");

            ui->checkBox->setText("34522<sub>5</sub>");
            ui->checkBox_2->setText("4096<sub>10</sub>");
            ui->checkBox_3->setText("10000<sub>8</sub>");

            zamek = 1;
        }


    }else{
        this->close();
    }
}
