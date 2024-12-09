#include "create_container_page.h"

createContainerPage::createContainerPage(QWidget *parent) : QWidget(parent), ui(new Ui::createContainerPage) {
    ui->setupUi(this); 
    connect(ui->backButton, &QPushButton::clicked, [=]() {
        emit buttonClicked("back");
    });

    QList<QPushButton*> containerButtons = {
        ui->createAlmaButton,
        ui->createAlpineButton,
        ui->createAmazonButton,
        ui->createArchButton,
        ui->createBazziteButton,
        ui->createCentButton,
        ui->createDebianButton,
        ui->createFedoraButton,
        ui->createSuseButton,
        ui->createRedhatButton,
        ui->createRockyButton,
        ui->createUbuntuButton,
        ui->createWolfiButton,
        ui->createClearButton,
        ui->createCrystalButton,
        ui->createDeepinButton,
        ui->createGentooButton,
        ui->createNeonButton,
        ui->createKaliButton,
        ui->createMintButton,
        ui->createNeuroButton,
        ui->createOracleButton
    };

    for (QPushButton* button : containerButtons) {
        connect(button, &QPushButton::clicked, [=]() {
            emit create_container(button->text());
        });
    }
}

createContainerPage::~createContainerPage() {
    delete ui;
}


