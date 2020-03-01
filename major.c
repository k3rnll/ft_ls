int 	major(unsigned long major)
{
	if (major < 16777215)
		return (0);
	return (int)(major >> 24);
}