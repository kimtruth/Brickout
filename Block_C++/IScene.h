#ifndef ISCENE_H
#define ISCENE_H

class IScene{
public:
	IScene(){}
	virtual ~IScene(){}
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Clear() = 0;

	virtual IScene * GetNextScene(){ return 0; }
	virtual bool IsEnd(){ return false; }
};

#endif