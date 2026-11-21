#ifndef GAME_PYTHON_BINDING_REGISTRATION_TABLES_H
#define GAME_PYTHON_BINDING_REGISTRATION_TABLES_H

struct FactoryPyObject;
typedef struct FactoryPyObject *(*FactoryPythonMethod)(struct FactoryPyObject *, struct FactoryPyObject *);
typedef struct PythonBindingMethodDef {
    const char *name;
    FactoryPythonMethod method;
    int flags;
    const char *documentation;
} PythonBindingMethodDef;
#ifdef __cplusplus
namespace SceneCallbacksMore { struct Binding; }
namespace SceneLateLeaf { struct Binding; }
/* Complete CPython 2.1 variable-link type layout. Populated callbacks retain
 * the parameter views of their recovered native providers. */
struct PythonVariableLinkTypeRecord {
    int references;
    void *type;
    int itemCount;
    const char *name;
    int basicSize;
    int itemSize;
    void (*deallocate)(FactoryPyObject *);
    int (*print)(SceneCallbacksMore::Binding *, void *);
    FactoryPyObject *(*getAttribute)(SceneLateLeaf::Binding *, const char *);
    int (*setAttribute)(SceneLateLeaf::Binding *, const char *, FactoryPyObject *);
    int (*compare)(FactoryPyObject *, FactoryPyObject *);
    FactoryPyObject *(*representation)();
    const void *numberMethods;
    const void *sequenceMethods;
    const void *mappingMethods;
    long (*hash)(FactoryPyObject *);
    FactoryPyObject *(*call)(FactoryPyObject *, FactoryPyObject *, FactoryPyObject *);
    FactoryPyObject *(*string)(FactoryPyObject *);
    FactoryPyObject *(*getAttributeObject)(FactoryPyObject *, FactoryPyObject *);
    int (*setAttributeObject)(FactoryPyObject *, FactoryPyObject *, FactoryPyObject *);
    const void *bufferMethods;
    long flags;
    const char *documentation;
    int (*traverse)(FactoryPyObject *, void *, void *);
    int (*clear)(FactoryPyObject *);
    FactoryPyObject *(*richCompare)(FactoryPyObject *, FactoryPyObject *, int);
    long weakListOffset;
};
extern "C" {
extern PythonVariableLinkTypeRecord lbl_802C1E78;
#else
typedef struct PythonVariableLinkTypeRecord PythonVariableLinkTypeRecord;
extern PythonVariableLinkTypeRecord lbl_802C1E78;
#endif
extern char lbl_802C1EE4[17];
#ifdef __cplusplus
}
#endif
#endif
