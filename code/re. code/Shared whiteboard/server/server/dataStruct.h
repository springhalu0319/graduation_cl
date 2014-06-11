#ifndef DATASTRUCT_H
#define DATASTRUCT_H

enum{line,circle,rectangle,ellipse};//������״
enum{conn,disconn,painted};//�ǽ������󣬻��ǻ�ͼ

class netAddr
{
public:
	unsigned char srcIP[4];
	unsigned char desIP[4];
};

class Point
{
public:
	int x;
	int y;
};

class userOp
{
public:
	int opKind;
	Point startPoint;
	Point endPoint;
};

class messageStruct
{
public:
	netAddr messageHeader;
	userOp userOpInfo;
};

#endif