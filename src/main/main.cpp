#include "constants.h"

#include <spdlog/spdlog.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QDateTimeEdit>

#include <QtCore/QSharedPointer>

using namespace ad;

int main(int argc, char** argv)
{
	spdlog::set_level(spdlog::level::trace);

	spdlog::debug("Hello world");

	QApplication app {argc, argv};

	QSharedPointer<QWidget>     window {new QWidget};
	QSharedPointer<QGridLayout> layout {new QGridLayout};
	QSharedPointer<QLabel>      nameLabel {new QLabel {"some cool label"}};
	QSharedPointer<QSpinBox>    ageSpinBox {new QSpinBox};
	ageSpinBox->setRange(1, 100);

	QPushButton button {QIcon {ad::constants::FILESAVEAS_PATH.c_str()}, "Push Me"};
	button.setToolTip("Click this to turn back the hands of time");

	layout->addWidget(nameLabel.get(), 0, 0);
	layout->addWidget(ageSpinBox.get(), 0, 1);
	layout->addWidget(&button, 1, 0);

	window->setLayout(layout.get());
	window->show();

	return app.exec();
}