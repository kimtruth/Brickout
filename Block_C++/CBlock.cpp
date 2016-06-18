#include "CBlock.h"
CBlock::CBlock() : IObject(0, 0, "бс"){

}
void CBlock::Set(){
}
void CBlock::Move(){

}

void CBlock::setNLife(int nLife){ this->nLife = nLife; }
int CBlock::getNLife(){ return this->nLife; }