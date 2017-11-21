#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "Simplex.hpp"
class Canvas : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT
private:
	Simplex m_current;
	std::vector<Point> m_points;
	size_t m_counters[3];
protected:
	virtual void initializeGL() override;
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;
public:
	Canvas(QWidget *parent);
	~Canvas();
public slots:
	void step();
};