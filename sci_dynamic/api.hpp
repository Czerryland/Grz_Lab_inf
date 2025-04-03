#ifndef SCI_DUMMYLIB_API_HPP
#define SCI_DUMMYLIB_API_HPP



#if defined(SCI_DUMMYLIB_EXPORTS)
    #define SCI_DUMMY_API_HPP __declspec(dllexport)
#else
    #define SCI_DUMMY_API_HPP __declspec(dllexport)
#endif



#endif // SCI_DUMMY_API_HPP