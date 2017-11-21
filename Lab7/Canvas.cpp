#include "Canvas.h"
size_t i = 4;
bool success = false;
Point opt;
std::mt19937_64 g((std::random_device())());
Canvas::Canvas(QWidget *parent) : QOpenGLWidget(parent), m_counters{0, 0, 0} {}
Canvas::~Canvas() {}

void Canvas::initializeGL() {
	initializeOpenGLFunctions();
	glLineWidth(2.5);
	glClearColor(0.15, 0, 0.3, 1);
	m_current = generate();
	m_points.push_back(m_current.a);
	m_points.push_back(m_current.b);
	m_points.push_back(m_current.c);
}
void Canvas::resizeGL(int w, int h) {
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-5, +5, -5, +5, -5, +5);
}
void Canvas::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT);

	//Coordinate System.
	glBegin(GL_LINES);
	glColor3f(0.25, 0.0, 0.45);
	glVertex2f(-5, 0);
	glVertex2f(+5, 0);
	glVertex2f(0, -5);
	glVertex2f(0, +5);
	glEnd();

	//Current simplex
	glBegin(GL_LINE_LOOP);
	glColor3f(0.55, 0.3, 0.7);
	glVertex2f(m_current.a.x, m_current.a.y);
	glVertex2f(m_current.b.x, m_current.b.y);
	glVertex2f(m_current.c.x, m_current.c.y);
	glEnd();

	//All the points
	glBegin(GL_QUADS);
	glColor3f(0.95, 0.7, 1.0);
	for (auto it : m_points) {
		glVertex2f(it.x - 0.1, it.y);
		glVertex2f(it.x, it.y - 0.1);
		glVertex2f(it.x + 0.1, it.y);
		glVertex2f(it.x, it.y + 0.1);
	}
	if (success) {
		glColor3f(0.95f, 0.f, 0.f);
		glVertex2f(opt.x - 0.1, opt.y);
		glVertex2f(opt.x, opt.y - 0.1);
		glVertex2f(opt.x + 0.1, opt.y);
		glVertex2f(opt.x, opt.y + 0.1);
	}
	glEnd();
}
Point shift(Value *s, Point const& a, Point const& b) {
	float x = s->x;
	float y = s->y;
	float cx = (a.x + b.x) / 2.f;
	float cy = (a.y + b.y) / 2.f;
	float dx = cx - x;
	float dy = cy - y;
	cx += dx * 1;
	cy += dy * 1;

	*s = Value(cx, cy, experiment(i++));
	return {cx, cy};
}
Point shift_simplex(Simplex &s, size_t *c) {
	if (s.a.v < s.b.v && s.a.v < s.c.v) {
		c[0] = 0; c[1]++; c[2]++;
		return shift(&s.a, s.b, s.c);
	} else if (s.b.v < s.a.v && s.b.v < s.c.v) {
		c[1] = 0; c[0]++; c[2]++;
		return shift(&s.b, s.a, s.c);
	} else if (s.c.v < s.b.v && s.c.v < s.a.v) {
		c[2] = 0; c[1]++; c[0]++;
		return shift(&s.c, s.b, s.a);
	}
}
void Canvas::step() {
	if (!success) {
		m_points.push_back(shift_simplex(m_current, m_counters));
		if (m_counters[0] >= n) {
			success = true;
			opt = m_current.a;
		} else if (m_counters[1] >= n) {
			success = true;
			opt = m_current.b;
		} else if(m_counters[2] >= n) {
			success = true;
			opt = m_current.c;
		}
	}
	update();
}