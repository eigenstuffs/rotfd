struct FactoryCallback { virtual ~FactoryCallback(); };
struct CFSM {
 virtual ~CFSM();
 virtual void configureCallbacks();
 virtual void configure(int);
 virtual void reset();
 signed char enabled,changing;char unknown06[2];
 int current,previous,pending,unknown14;
 unsigned long long active,activeCount;
 int count;FactoryCallback**callbacks;
 CFSM();
};
typedef char CheckCFSMSize[sizeof(CFSM)==0x30?1:-1];
