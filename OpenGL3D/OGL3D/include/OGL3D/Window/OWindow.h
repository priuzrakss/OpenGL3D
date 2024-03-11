#pragma once
class OWindow
{

	

public:
	OWindow();
	~OWindow();

	void makeCurrentCntext();
	void present(bool vsync);
private:
	void* m_handle = nullptr;
	void* m_context = nullptr;
};

