#include "utils.h"

void loadAppStyleSheet(QApplication &app, const QString &fileName) {
    QFile file(fileName);
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
    } else {
        qWarning("Could not open stylesheet file: %s", qPrintable(file.errorString()));
    }
}

void loadWidgetStyleSheet(QWidget *widget, const QString &fileName) {
    QFile file(fileName);
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        widget->setStyleSheet(styleSheet);
    } else {
        qWarning("Could not open stylesheet file: %s", qPrintable(file.errorString()));
    }
}

void system_exec(const std::string& cmd) {
    QString qCmd = QString::fromStdString(cmd);
    QProcess process;
    QStringList arguments = QProcess::splitCommand(qCmd);
    if (arguments.isEmpty()) {
        qCritical() << "Invalid command:" << qCmd;
        std::exit(EXIT_FAILURE);
    }

    QString program = arguments.takeFirst(); 
    process.start(program, arguments);

    if (!process.waitForFinished()) {
        qCritical() << "Failed to execute command:" << qCmd;
        qCritical() << "Error:" << process.errorString();
        std::exit(EXIT_FAILURE);
    }

    if (process.exitStatus() != QProcess::NormalExit || process.exitCode() != 0) {
        qCritical() << "Command failed with exit code:" << process.exitCode();
        std::exit(EXIT_FAILURE);
    }
}

std::string exec(const std::string& cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, int (*)(FILE*)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::vector<std::string> list_items(const std::string& input_text) {
    std::vector<std::string> item_list;
    std::istringstream input_stream(input_text);
    std::string item;

    while (input_stream >> item) {
        item_list.push_back(item);
    }
    return item_list;
}

