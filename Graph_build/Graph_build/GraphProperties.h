class GraphProperties
{
public:
	double width, height;
	double scale, step;
	double centreX, centreY;
	double left, right, up, down;
	double window_width, window_height;

	GraphProperties();
	
	void set_width(double tmp);

	void set_centreX(int tmp);

	void set_centreY(int tmp);
};