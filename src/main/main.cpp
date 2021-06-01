#include <spdlog/spdlog.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

int main(int argc, char** argv)
{
	spdlog::set_level(spdlog::level::trace);

	spdlog::debug("Hello world");

	QApplication app {argc, argv};
	QLabel       label {"Hello world !"};
	label.show();

	return app.exec();
}