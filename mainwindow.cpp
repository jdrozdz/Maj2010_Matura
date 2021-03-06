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

    if(licznik == 2 && zamek == 1){
        (!ui->checkBox->isChecked()) ? pkt_tmp++ : 0;
        (ui->checkBox_2->isChecked()) ? pkt_tmp++ : 0;
        (ui->checkBox_3->isChecked()) ? pkt_tmp++ : 0;
        licznik++;
        pkt += pkt_tmp;
        zamek = 0;
    }

    if(licznik == 3 && zamek == 1){
        (ui->checkBox->isChecked()) ? pkt_tmp++ : 0;
        (!ui->checkBox_2->isChecked()) ? pkt_tmp++ : 0;
        (!ui->checkBox_3->isChecked()) ? pkt_tmp++ : 0;
        licznik++;
        pkt += pkt_tmp;
        zamek = 0;
    }

    if(licznik == 4 && zamek == 1){
        (ui->checkBox->isChecked()) ? pkt_tmp++ : 0;
        (ui->checkBox_2->isChecked()) ? pkt_tmp++ : 0;
        (!ui->checkBox_3->isChecked()) ? pkt_tmp++ : 0;
        licznik++;
        pkt += pkt_tmp;
        zamek = 0;
    }

    QMessageBox::StandardButton odpowiedz = QMessageBox::question(this, "", QString("Brawo zdobyłeś %1 %2.\nW sumie masz %3 %4\nCzy kontynuwać?").arg(pkt_tmp).arg( pkt_tmp > 1 ? "punkty" : "punkt" ).arg(pkt).arg( pkt_tmp > 1 ? "punkty" : "punkt" ));
    pkt_tmp = 0;

    if(odpowiedz == QMessageBox::Yes){

        ui->checkBox->setChecked(false); ui->checkBox_2->setChecked(false); ui->checkBox_3->setChecked(false);

        // pytanie b
        if(licznik == 1){
            QPixmap obrazek(":/algorytm1");
            ui->label->setPixmap(obrazek);
            // ui->label->setMask(obrazek.mask());

            ui->checkBox->setText("Algorytm znajduje NWW(a,b)");
            ui->checkBox_2->setText("Algorytm znajduje NWD(a,b)");
            ui->checkBox_3->setText("liczbę pierwszą większą od a i mniejszą od b.");
            zamek = 1;
        }
        // c
        if(licznik == 2){
            ui->label->setText("Liczba 1000<sub>16</sub> to: ");

            ui->checkBox->setText("34522(5)");
            ui->checkBox_2->setText("4096(10)");
            ui->checkBox_3->setText("10000(8)");

            zamek = 1;
        }
        // d
        if(licznik == 3){
            ui->label->setText("Program zapobiegający włamaniom do systemu i kontrolujący pakiety sieciowe to");
            ui->checkBox->setText("firewall");
            ui->checkBox_2->setText("keylogger");
            ui->checkBox_3->setText("filtr antyspamowy");

            zamek = 1;
        }
        // d
        if(licznik == 4){
            ui->label->setText("Format plików graficznych dla grafiki rastrowej to");
            ui->checkBox->setText("BMP");
            ui->checkBox_2->setText("JPG");
            ui->checkBox_3->setText("GIF");

            zamek = 1;
        }

        if(licznik > 4){
            QString wiedza = "";
            if(pkt >= 12 ) wiedza = "Bardzo dobry";
            if(pkt >= 9 && pkt < 12) wiedza = "dobry";
            if(pkt >= 3 && pkt < 9) wiedza = "słaby";
            if(pkt < 3) wiedza = "bardzo słaby";

            QMessageBox::information(this, "Ocena", QString("Twoja liczba punktów to %1\nTwój zasób wiedzy jest %2").arg(pkt).arg(wiedza) );
            this->close();
        }


    }else{
        this->close();
    }
}
