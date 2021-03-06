#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

	auto app = QGuiApplication(argc, argv);
	auto engine = QQmlApplicationEngine();
	engine.load("qrc:/root/qml/main.qml");
 
	return app.exec();
}
