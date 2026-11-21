struct ChainVector {
    float x,y,z;
    ChainVector(){}
    ChainVector(float a,float b,float c):x(a),y(b),z(c){}
    void operator=(const ChainVector&v){x=v.x;y=v.y;z=v.z;}
};
struct ChainQuaternion {
    ChainVector vector;
    float w;
    void operator=(const ChainQuaternion&q){vector=q.vector;w=q.w;}
};
struct ChainRecord {ChainQuaternion quaternion;short kind;char unknown12[2];};
struct ChainStorage {char unknown0[8];};
struct ChainOwner:ChainStorage {
    virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
    virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
    virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
    virtual void slot38();virtual ChainQuaternion*value();
    char unknownC[0x18];int count;void*unknown28;ChainRecord*records;
};
struct ChainTarget {char unknown0[0x124];float*matrix;};
extern "C" {extern const float lbl_8037B500;void fn_801F0A20(ChainQuaternion*,const ChainQuaternion*,const ChainRecord*);}
extern "C" void fn_802524B4(ChainOwner*self,ChainTarget*target){
    ChainRecord*record=self->records;
    self->value()->vector=ChainVector(target->matrix[12],target->matrix[13],target->matrix[14]);
    self->value()->w=lbl_8037B500;
    if(record->kind>=0){
        int count=self->count;
        while(count!=0&&record->kind>=0){
            ChainQuaternion result;
            fn_801F0A20(&result,self->value(),record);
            *self->value()=result;
            ++record;--count;
        }
    }
}
