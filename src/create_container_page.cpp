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
        ui->createOracleButton, 
        ui->createSlackwareButton, 
        ui->createSteamButton, 
        ui->createVanillaButton, 
        ui->createVoidButton 
    };

    for (QPushButton* button : containerButtons) {
        connect(button, &QPushButton::clicked, [=]() {
            bool ok;
            QString containerName = QInputDialog::getText(this, 
                tr("Create Container"), 
                tr("Enter container name for %1:").arg(button->text()),
                QLineEdit::Normal, 
                button->text(), 
                &ok);
            
            if (ok && !containerName.isEmpty()) {
                create_container(button->text().toStdString(), containerName.toStdString());
            }
        });
    }
}

createContainerPage::~createContainerPage() {
    delete ui;
}


