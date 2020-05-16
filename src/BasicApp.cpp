#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Color.h"

#include "dot.hpp"

using namespace ci;
using namespace ci::app;

// We'll create a new Cinder Application by deriving from the App class.
class BasicApp : public App {
  public:
	// Cinder will call 'draw' each time the contents of the window need to be redrawn.
	void draw() override;
    void setup() override;

  private:
	// This will maintain a list of points which we will draw line segments between
	std::vector<vec2> mPoints;
    Dot dot;
};

void BasicApp::draw()
{
	// Clear the contents of the window. This call will clear
	// both the color and depth buffers. 
	gl::clear( Color::gray( 0.1f ) );
    dot.draw();
}

void prepareSettings( BasicApp::Settings* settings )
{
	settings->setMultiTouchEnabled( false );
}

void BasicApp::setup() {
    dot = Dot(100.0f, 100.0f, Colorf(1.f, 0.0f, 0.0f));
}

// This line tells Cinder to actually create and run the application.
CINDER_APP( BasicApp, RendererGl, prepareSettings )
