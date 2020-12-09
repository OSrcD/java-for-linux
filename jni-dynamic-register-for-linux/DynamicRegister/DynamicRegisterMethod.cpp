#include <DynamicRegisterMethod.h>

using namespace std;

char* javaClass []  = {

    (char*)"com/ossit/demo01/App",

};

static JNINativeMethod getMethod[1][2] = {

    {
        {(char*)"printInstructionTime",(char*)"()V",(void*)printInstructionTime},
        {(char*)"test",(char*)"()V",(void*)test}
       
    }
    
};

int registerNativeMethods(JNIEnv* env,const char* name,
    JNINativeMethod* methods,jint nmethods){

    jclass jcls;
    
    jcls = env->FindClass(name);

    if(jcls == NULL) {

        return JNI_FALSE;


    }

    if(env->RegisterNatives(jcls,methods,nmethods) < 0){

        return JNI_FALSE;

    }
    
    return JNI_TRUE;

}


JNIEXPORT int JNICALL JNI_OnLoad(JavaVM* vm,void* reserved){
    
    JNIEnv* env;

    if(vm->GetEnv(reinterpret_cast<void**>(&env),JNI_VERSION_1_6) != JNI_OK){

        return JNI_FALSE;

    }

    int count=0;

    for(int i=0;i < sizeof(javaClass)/sizeof(javaClass[0]);i++){
        
        for(int j=0;j< sizeof(getMethod[i])/sizeof(getMethod[i][0]);j++){
            
            if(getMethod[i][j].fnPtr != NULL){

                count++;
                
            }
        }

        registerNativeMethods(env,javaClass[i],&getMethod[i][0],count);

        count = 0;
    }

    cout << "LoadAlgorithmLibrary" << endl;
    
    return JNI_VERSION_1_6;
}


