static PyObject* pyopencv_cv_AKAZE_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_descriptor_type = NULL;
    AKAZE_DescriptorType descriptor_type=AKAZE::DESCRIPTOR_MLDB;
    PyObject* pyobj_descriptor_size = NULL;
    int descriptor_size=0;
    PyObject* pyobj_descriptor_channels = NULL;
    int descriptor_channels=3;
    PyObject* pyobj_threshold = NULL;
    float threshold=0.001f;
    PyObject* pyobj_nOctaves = NULL;
    int nOctaves=4;
    PyObject* pyobj_nOctaveLayers = NULL;
    int nOctaveLayers=4;
    PyObject* pyobj_diffusivity = NULL;
    KAZE_DiffusivityType diffusivity=KAZE::DIFF_PM_G2;
    Ptr<AKAZE> retval;

    const char* keywords[] = { "descriptor_type", "descriptor_size", "descriptor_channels", "threshold", "nOctaves", "nOctaveLayers", "diffusivity", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOOOOO:AKAZE_create", (char**)keywords, &pyobj_descriptor_type, &pyobj_descriptor_size, &pyobj_descriptor_channels, &pyobj_threshold, &pyobj_nOctaves, &pyobj_nOctaveLayers, &pyobj_diffusivity) &&
        pyopencv_to(pyobj_descriptor_type, descriptor_type, ArgInfo("descriptor_type", 0)) &&
        pyopencv_to(pyobj_descriptor_size, descriptor_size, ArgInfo("descriptor_size", 0)) &&
        pyopencv_to(pyobj_descriptor_channels, descriptor_channels, ArgInfo("descriptor_channels", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_nOctaves, nOctaves, ArgInfo("nOctaves", 0)) &&
        pyopencv_to(pyobj_nOctaveLayers, nOctaveLayers, ArgInfo("nOctaveLayers", 0)) &&
        pyopencv_to(pyobj_diffusivity, diffusivity, ArgInfo("diffusivity", 0)) )
    {
        ERRWRAP2(retval = cv::AKAZE::create(descriptor_type, descriptor_size, descriptor_channels, threshold, nOctaves, nOctaveLayers, diffusivity));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_AgastFeatureDetector_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_threshold = NULL;
    int threshold=10;
    PyObject* pyobj_nonmaxSuppression = NULL;
    bool nonmaxSuppression=true;
    PyObject* pyobj_type = NULL;
    AgastFeatureDetector_DetectorType type=AgastFeatureDetector::OAST_9_16;
    Ptr<AgastFeatureDetector> retval;

    const char* keywords[] = { "threshold", "nonmaxSuppression", "type", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:AgastFeatureDetector_create", (char**)keywords, &pyobj_threshold, &pyobj_nonmaxSuppression, &pyobj_type) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_nonmaxSuppression, nonmaxSuppression, ArgInfo("nonmaxSuppression", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = cv::AgastFeatureDetector::create(threshold, nonmaxSuppression, type));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_BFMatcher_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_crossCheck = NULL;
    bool crossCheck=false;
    Ptr<BFMatcher> retval;

    const char* keywords[] = { "normType", "crossCheck", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OO:BFMatcher_create", (char**)keywords, &pyobj_normType, &pyobj_crossCheck) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to(pyobj_crossCheck, crossCheck, ArgInfo("crossCheck", 0)) )
    {
        ERRWRAP2(retval = cv::BFMatcher::create(normType, crossCheck));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_BRISK_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_thresh = NULL;
    int thresh=30;
    PyObject* pyobj_octaves = NULL;
    int octaves=3;
    PyObject* pyobj_patternScale = NULL;
    float patternScale=1.0f;
    Ptr<BRISK> retval;

    const char* keywords[] = { "thresh", "octaves", "patternScale", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:BRISK_create", (char**)keywords, &pyobj_thresh, &pyobj_octaves, &pyobj_patternScale) &&
        pyopencv_to(pyobj_thresh, thresh, ArgInfo("thresh", 0)) &&
        pyopencv_to(pyobj_octaves, octaves, ArgInfo("octaves", 0)) &&
        pyopencv_to(pyobj_patternScale, patternScale, ArgInfo("patternScale", 0)) )
    {
        ERRWRAP2(retval = cv::BRISK::create(thresh, octaves, patternScale));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_radiusList = NULL;
    vector_float radiusList;
    PyObject* pyobj_numberList = NULL;
    vector_int numberList;
    PyObject* pyobj_dMax = NULL;
    float dMax=5.85f;
    PyObject* pyobj_dMin = NULL;
    float dMin=8.2f;
    PyObject* pyobj_indexChange = NULL;
    vector_int indexChange=std::vector<int>();
    Ptr<BRISK> retval;

    const char* keywords[] = { "radiusList", "numberList", "dMax", "dMin", "indexChange", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:BRISK_create", (char**)keywords, &pyobj_radiusList, &pyobj_numberList, &pyobj_dMax, &pyobj_dMin, &pyobj_indexChange) &&
        pyopencv_to(pyobj_radiusList, radiusList, ArgInfo("radiusList", 0)) &&
        pyopencv_to(pyobj_numberList, numberList, ArgInfo("numberList", 0)) &&
        pyopencv_to(pyobj_dMax, dMax, ArgInfo("dMax", 0)) &&
        pyopencv_to(pyobj_dMin, dMin, ArgInfo("dMin", 0)) &&
        pyopencv_to(pyobj_indexChange, indexChange, ArgInfo("indexChange", 0)) )
    {
        ERRWRAP2(retval = cv::BRISK::create(radiusList, numberList, dMax, dMin, indexChange));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_thresh = NULL;
    int thresh=0;
    PyObject* pyobj_octaves = NULL;
    int octaves=0;
    PyObject* pyobj_radiusList = NULL;
    vector_float radiusList;
    PyObject* pyobj_numberList = NULL;
    vector_int numberList;
    PyObject* pyobj_dMax = NULL;
    float dMax=5.85f;
    PyObject* pyobj_dMin = NULL;
    float dMin=8.2f;
    PyObject* pyobj_indexChange = NULL;
    vector_int indexChange=std::vector<int>();
    Ptr<BRISK> retval;

    const char* keywords[] = { "thresh", "octaves", "radiusList", "numberList", "dMax", "dMin", "indexChange", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:BRISK_create", (char**)keywords, &pyobj_thresh, &pyobj_octaves, &pyobj_radiusList, &pyobj_numberList, &pyobj_dMax, &pyobj_dMin, &pyobj_indexChange) &&
        pyopencv_to(pyobj_thresh, thresh, ArgInfo("thresh", 0)) &&
        pyopencv_to(pyobj_octaves, octaves, ArgInfo("octaves", 0)) &&
        pyopencv_to(pyobj_radiusList, radiusList, ArgInfo("radiusList", 0)) &&
        pyopencv_to(pyobj_numberList, numberList, ArgInfo("numberList", 0)) &&
        pyopencv_to(pyobj_dMax, dMax, ArgInfo("dMax", 0)) &&
        pyopencv_to(pyobj_dMin, dMin, ArgInfo("dMin", 0)) &&
        pyopencv_to(pyobj_indexChange, indexChange, ArgInfo("indexChange", 0)) )
    {
        ERRWRAP2(retval = cv::BRISK::create(thresh, octaves, radiusList, numberList, dMax, dMin, indexChange));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_CamShift(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_probImage = NULL;
    Mat probImage;
    PyObject* pyobj_window = NULL;
    Rect window;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;
    RotatedRect retval;

    const char* keywords[] = { "probImage", "window", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:CamShift", (char**)keywords, &pyobj_probImage, &pyobj_window, &pyobj_criteria) &&
        pyopencv_to(pyobj_probImage, probImage, ArgInfo("probImage", 0)) &&
        pyopencv_to(pyobj_window, window, ArgInfo("window", 1)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::CamShift(probImage, window, criteria));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(window));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_probImage = NULL;
    UMat probImage;
    PyObject* pyobj_window = NULL;
    Rect window;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;
    RotatedRect retval;

    const char* keywords[] = { "probImage", "window", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:CamShift", (char**)keywords, &pyobj_probImage, &pyobj_window, &pyobj_criteria) &&
        pyopencv_to(pyobj_probImage, probImage, ArgInfo("probImage", 0)) &&
        pyopencv_to(pyobj_window, window, ArgInfo("window", 1)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::CamShift(probImage, window, criteria));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(window));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_Canny(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_edges = NULL;
    Mat edges;
    PyObject* pyobj_threshold1 = NULL;
    double threshold1=0;
    PyObject* pyobj_threshold2 = NULL;
    double threshold2=0;
    PyObject* pyobj_apertureSize = NULL;
    int apertureSize=3;
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=false;

    const char* keywords[] = { "image", "threshold1", "threshold2", "edges", "apertureSize", "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:Canny", (char**)keywords, &pyobj_image, &pyobj_threshold1, &pyobj_threshold2, &pyobj_edges, &pyobj_apertureSize, &pyobj_L2gradient) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to(pyobj_threshold1, threshold1, ArgInfo("threshold1", 0)) &&
        pyopencv_to(pyobj_threshold2, threshold2, ArgInfo("threshold2", 0)) &&
        pyopencv_to(pyobj_apertureSize, apertureSize, ArgInfo("apertureSize", 0)) &&
        pyopencv_to(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(cv::Canny(image, edges, threshold1, threshold2, apertureSize, L2gradient));
        return pyopencv_from(edges);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_edges = NULL;
    UMat edges;
    PyObject* pyobj_threshold1 = NULL;
    double threshold1=0;
    PyObject* pyobj_threshold2 = NULL;
    double threshold2=0;
    PyObject* pyobj_apertureSize = NULL;
    int apertureSize=3;
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=false;

    const char* keywords[] = { "image", "threshold1", "threshold2", "edges", "apertureSize", "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:Canny", (char**)keywords, &pyobj_image, &pyobj_threshold1, &pyobj_threshold2, &pyobj_edges, &pyobj_apertureSize, &pyobj_L2gradient) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to(pyobj_threshold1, threshold1, ArgInfo("threshold1", 0)) &&
        pyopencv_to(pyobj_threshold2, threshold2, ArgInfo("threshold2", 0)) &&
        pyopencv_to(pyobj_apertureSize, apertureSize, ArgInfo("apertureSize", 0)) &&
        pyopencv_to(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(cv::Canny(image, edges, threshold1, threshold2, apertureSize, L2gradient));
        return pyopencv_from(edges);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_dx = NULL;
    Mat dx;
    PyObject* pyobj_dy = NULL;
    Mat dy;
    PyObject* pyobj_edges = NULL;
    Mat edges;
    PyObject* pyobj_threshold1 = NULL;
    double threshold1=0;
    PyObject* pyobj_threshold2 = NULL;
    double threshold2=0;
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=false;

    const char* keywords[] = { "dx", "dy", "threshold1", "threshold2", "edges", "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:Canny", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_threshold1, &pyobj_threshold2, &pyobj_edges, &pyobj_L2gradient) &&
        pyopencv_to(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to(pyobj_threshold1, threshold1, ArgInfo("threshold1", 0)) &&
        pyopencv_to(pyobj_threshold2, threshold2, ArgInfo("threshold2", 0)) &&
        pyopencv_to(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(cv::Canny(dx, dy, edges, threshold1, threshold2, L2gradient));
        return pyopencv_from(edges);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_dx = NULL;
    UMat dx;
    PyObject* pyobj_dy = NULL;
    UMat dy;
    PyObject* pyobj_edges = NULL;
    UMat edges;
    PyObject* pyobj_threshold1 = NULL;
    double threshold1=0;
    PyObject* pyobj_threshold2 = NULL;
    double threshold2=0;
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=false;

    const char* keywords[] = { "dx", "dy", "threshold1", "threshold2", "edges", "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:Canny", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_threshold1, &pyobj_threshold2, &pyobj_edges, &pyobj_L2gradient) &&
        pyopencv_to(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to(pyobj_threshold1, threshold1, ArgInfo("threshold1", 0)) &&
        pyopencv_to(pyobj_threshold2, threshold2, ArgInfo("threshold2", 0)) &&
        pyopencv_to(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(cv::Canny(dx, dy, edges, threshold1, threshold2, L2gradient));
        return pyopencv_from(edges);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_CascadeClassifier_convert(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_oldcascade = NULL;
    String oldcascade;
    PyObject* pyobj_newcascade = NULL;
    String newcascade;
    bool retval;

    const char* keywords[] = { "oldcascade", "newcascade", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:CascadeClassifier_convert", (char**)keywords, &pyobj_oldcascade, &pyobj_newcascade) &&
        pyopencv_to(pyobj_oldcascade, oldcascade, ArgInfo("oldcascade", 0)) &&
        pyopencv_to(pyobj_newcascade, newcascade, ArgInfo("newcascade", 0)) )
    {
        ERRWRAP2(retval = cv::CascadeClassifier::convert(oldcascade, newcascade));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_DISOpticalFlow_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_preset = NULL;
    int preset=DISOpticalFlow::PRESET_FAST;
    Ptr<DISOpticalFlow> retval;

    const char* keywords[] = { "preset", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|O:DISOpticalFlow_create", (char**)keywords, &pyobj_preset) &&
        pyopencv_to(pyobj_preset, preset, ArgInfo("preset", 0)) )
    {
        ERRWRAP2(retval = cv::DISOpticalFlow::create(preset));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_DescriptorMatcher_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_descriptorMatcherType = NULL;
    String descriptorMatcherType;
    Ptr<DescriptorMatcher> retval;

    const char* keywords[] = { "descriptorMatcherType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:DescriptorMatcher_create", (char**)keywords, &pyobj_descriptorMatcherType) &&
        pyopencv_to(pyobj_descriptorMatcherType, descriptorMatcherType, ArgInfo("descriptorMatcherType", 0)) )
    {
        ERRWRAP2(retval = cv::DescriptorMatcher::create(descriptorMatcherType));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_matcherType = NULL;
    DescriptorMatcher_MatcherType matcherType=static_cast<DescriptorMatcher_MatcherType>(0);
    Ptr<DescriptorMatcher> retval;

    const char* keywords[] = { "matcherType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:DescriptorMatcher_create", (char**)keywords, &pyobj_matcherType) &&
        pyopencv_to(pyobj_matcherType, matcherType, ArgInfo("matcherType", 0)) )
    {
        ERRWRAP2(retval = cv::DescriptorMatcher::create(matcherType));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_EMD(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_signature1 = NULL;
    Mat signature1;
    PyObject* pyobj_signature2 = NULL;
    Mat signature2;
    PyObject* pyobj_distType = NULL;
    int distType=0;
    PyObject* pyobj_cost = NULL;
    Mat cost;
    PyObject* pyobj_lowerBound = NULL;
    Ptr<float> lowerBound;
    PyObject* pyobj_flow = NULL;
    Mat flow;
    float retval;

    const char* keywords[] = { "signature1", "signature2", "distType", "cost", "lowerBound", "flow", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:EMD", (char**)keywords, &pyobj_signature1, &pyobj_signature2, &pyobj_distType, &pyobj_cost, &pyobj_lowerBound, &pyobj_flow) &&
        pyopencv_to(pyobj_signature1, signature1, ArgInfo("signature1", 0)) &&
        pyopencv_to(pyobj_signature2, signature2, ArgInfo("signature2", 0)) &&
        pyopencv_to(pyobj_distType, distType, ArgInfo("distType", 0)) &&
        pyopencv_to(pyobj_cost, cost, ArgInfo("cost", 0)) &&
        pyopencv_to(pyobj_lowerBound, lowerBound, ArgInfo("lowerBound", 1)) &&
        pyopencv_to(pyobj_flow, flow, ArgInfo("flow", 1)) )
    {
        ERRWRAP2(retval = cv::wrapperEMD(signature1, signature2, distType, cost, lowerBound, flow));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(lowerBound), pyopencv_from(flow));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_signature1 = NULL;
    UMat signature1;
    PyObject* pyobj_signature2 = NULL;
    UMat signature2;
    PyObject* pyobj_distType = NULL;
    int distType=0;
    PyObject* pyobj_cost = NULL;
    UMat cost;
    PyObject* pyobj_lowerBound = NULL;
    Ptr<float> lowerBound;
    PyObject* pyobj_flow = NULL;
    UMat flow;
    float retval;

    const char* keywords[] = { "signature1", "signature2", "distType", "cost", "lowerBound", "flow", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:EMD", (char**)keywords, &pyobj_signature1, &pyobj_signature2, &pyobj_distType, &pyobj_cost, &pyobj_lowerBound, &pyobj_flow) &&
        pyopencv_to(pyobj_signature1, signature1, ArgInfo("signature1", 0)) &&
        pyopencv_to(pyobj_signature2, signature2, ArgInfo("signature2", 0)) &&
        pyopencv_to(pyobj_distType, distType, ArgInfo("distType", 0)) &&
        pyopencv_to(pyobj_cost, cost, ArgInfo("cost", 0)) &&
        pyopencv_to(pyobj_lowerBound, lowerBound, ArgInfo("lowerBound", 1)) &&
        pyopencv_to(pyobj_flow, flow, ArgInfo("flow", 1)) )
    {
        ERRWRAP2(retval = cv::wrapperEMD(signature1, signature2, distType, cost, lowerBound, flow));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(lowerBound), pyopencv_from(flow));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_FarnebackOpticalFlow_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_numLevels = NULL;
    int numLevels=5;
    PyObject* pyobj_pyrScale = NULL;
    double pyrScale=0.5;
    PyObject* pyobj_fastPyramids = NULL;
    bool fastPyramids=false;
    PyObject* pyobj_winSize = NULL;
    int winSize=13;
    PyObject* pyobj_numIters = NULL;
    int numIters=10;
    PyObject* pyobj_polyN = NULL;
    int polyN=5;
    PyObject* pyobj_polySigma = NULL;
    double polySigma=1.1;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    Ptr<FarnebackOpticalFlow> retval;

    const char* keywords[] = { "numLevels", "pyrScale", "fastPyramids", "winSize", "numIters", "polyN", "polySigma", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOOOOOO:FarnebackOpticalFlow_create", (char**)keywords, &pyobj_numLevels, &pyobj_pyrScale, &pyobj_fastPyramids, &pyobj_winSize, &pyobj_numIters, &pyobj_polyN, &pyobj_polySigma, &pyobj_flags) &&
        pyopencv_to(pyobj_numLevels, numLevels, ArgInfo("numLevels", 0)) &&
        pyopencv_to(pyobj_pyrScale, pyrScale, ArgInfo("pyrScale", 0)) &&
        pyopencv_to(pyobj_fastPyramids, fastPyramids, ArgInfo("fastPyramids", 0)) &&
        pyopencv_to(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to(pyobj_numIters, numIters, ArgInfo("numIters", 0)) &&
        pyopencv_to(pyobj_polyN, polyN, ArgInfo("polyN", 0)) &&
        pyopencv_to(pyobj_polySigma, polySigma, ArgInfo("polySigma", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::FarnebackOpticalFlow::create(numLevels, pyrScale, fastPyramids, winSize, numIters, polyN, polySigma, flags));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FastFeatureDetector_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_threshold = NULL;
    int threshold=10;
    PyObject* pyobj_nonmaxSuppression = NULL;
    bool nonmaxSuppression=true;
    PyObject* pyobj_type = NULL;
    FastFeatureDetector_DetectorType type=FastFeatureDetector::TYPE_9_16;
    Ptr<FastFeatureDetector> retval;

    const char* keywords[] = { "threshold", "nonmaxSuppression", "type", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:FastFeatureDetector_create", (char**)keywords, &pyobj_threshold, &pyobj_nonmaxSuppression, &pyobj_type) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_nonmaxSuppression, nonmaxSuppression, ArgInfo("nonmaxSuppression", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = cv::FastFeatureDetector::create(threshold, nonmaxSuppression, type));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FlannBasedMatcher_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    Ptr<FlannBasedMatcher> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::FlannBasedMatcher::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GFTTDetector_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=1000;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0.01;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=1;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=3;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;
    Ptr<GFTTDetector> retval;

    const char* keywords[] = { "maxCorners", "qualityLevel", "minDistance", "blockSize", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOOOO:GFTTDetector_create", (char**)keywords, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_blockSize, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(retval = cv::GFTTDetector::create(maxCorners, qualityLevel, minDistance, blockSize, useHarrisDetector, k));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_gradiantSize = NULL;
    int gradiantSize=0;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;
    Ptr<GFTTDetector> retval;

    const char* keywords[] = { "maxCorners", "qualityLevel", "minDistance", "blockSize", "gradiantSize", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OO:GFTTDetector_create", (char**)keywords, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_blockSize, &pyobj_gradiantSize, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_gradiantSize, gradiantSize, ArgInfo("gradiantSize", 0)) &&
        pyopencv_to(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(retval = cv::GFTTDetector::create(maxCorners, qualityLevel, minDistance, blockSize, gradiantSize, useHarrisDetector, k));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_GaussianBlur(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_sigmaX = NULL;
    double sigmaX=0;
    PyObject* pyobj_sigmaY = NULL;
    double sigmaY=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "sigmaX", "dst", "sigmaY", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:GaussianBlur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_sigmaX, &pyobj_dst, &pyobj_sigmaY, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_sigmaX, sigmaX, ArgInfo("sigmaX", 0)) &&
        pyopencv_to(pyobj_sigmaY, sigmaY, ArgInfo("sigmaY", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::GaussianBlur(src, dst, ksize, sigmaX, sigmaY, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_sigmaX = NULL;
    double sigmaX=0;
    PyObject* pyobj_sigmaY = NULL;
    double sigmaY=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "sigmaX", "dst", "sigmaY", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:GaussianBlur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_sigmaX, &pyobj_dst, &pyobj_sigmaY, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_sigmaX, sigmaX, ArgInfo("sigmaX", 0)) &&
        pyopencv_to(pyobj_sigmaY, sigmaY, ArgInfo("sigmaY", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::GaussianBlur(src, dst, ksize, sigmaX, sigmaY, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_HOGDescriptor_getDaimlerPeopleDetector(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    std::vector<float> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::HOGDescriptor::getDaimlerPeopleDetector());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_HOGDescriptor_getDefaultPeopleDetector(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    std::vector<float> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::HOGDescriptor::getDefaultPeopleDetector());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_HoughCircles(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_circles = NULL;
    Mat circles;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_dp = NULL;
    double dp=0;
    PyObject* pyobj_minDist = NULL;
    double minDist=0;
    PyObject* pyobj_param1 = NULL;
    double param1=100;
    PyObject* pyobj_param2 = NULL;
    double param2=100;
    PyObject* pyobj_minRadius = NULL;
    int minRadius=0;
    PyObject* pyobj_maxRadius = NULL;
    int maxRadius=0;

    const char* keywords[] = { "image", "method", "dp", "minDist", "circles", "param1", "param2", "minRadius", "maxRadius", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:HoughCircles", (char**)keywords, &pyobj_image, &pyobj_method, &pyobj_dp, &pyobj_minDist, &pyobj_circles, &pyobj_param1, &pyobj_param2, &pyobj_minRadius, &pyobj_maxRadius) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_circles, circles, ArgInfo("circles", 1)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_dp, dp, ArgInfo("dp", 0)) &&
        pyopencv_to(pyobj_minDist, minDist, ArgInfo("minDist", 0)) &&
        pyopencv_to(pyobj_param1, param1, ArgInfo("param1", 0)) &&
        pyopencv_to(pyobj_param2, param2, ArgInfo("param2", 0)) &&
        pyopencv_to(pyobj_minRadius, minRadius, ArgInfo("minRadius", 0)) &&
        pyopencv_to(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) )
    {
        ERRWRAP2(cv::HoughCircles(image, circles, method, dp, minDist, param1, param2, minRadius, maxRadius));
        return pyopencv_from(circles);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_circles = NULL;
    UMat circles;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_dp = NULL;
    double dp=0;
    PyObject* pyobj_minDist = NULL;
    double minDist=0;
    PyObject* pyobj_param1 = NULL;
    double param1=100;
    PyObject* pyobj_param2 = NULL;
    double param2=100;
    PyObject* pyobj_minRadius = NULL;
    int minRadius=0;
    PyObject* pyobj_maxRadius = NULL;
    int maxRadius=0;

    const char* keywords[] = { "image", "method", "dp", "minDist", "circles", "param1", "param2", "minRadius", "maxRadius", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:HoughCircles", (char**)keywords, &pyobj_image, &pyobj_method, &pyobj_dp, &pyobj_minDist, &pyobj_circles, &pyobj_param1, &pyobj_param2, &pyobj_minRadius, &pyobj_maxRadius) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_circles, circles, ArgInfo("circles", 1)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_dp, dp, ArgInfo("dp", 0)) &&
        pyopencv_to(pyobj_minDist, minDist, ArgInfo("minDist", 0)) &&
        pyopencv_to(pyobj_param1, param1, ArgInfo("param1", 0)) &&
        pyopencv_to(pyobj_param2, param2, ArgInfo("param2", 0)) &&
        pyopencv_to(pyobj_minRadius, minRadius, ArgInfo("minRadius", 0)) &&
        pyopencv_to(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) )
    {
        ERRWRAP2(cv::HoughCircles(image, circles, method, dp, minDist, param1, param2, minRadius, maxRadius));
        return pyopencv_from(circles);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_HoughLines(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_lines = NULL;
    Mat lines;
    PyObject* pyobj_rho = NULL;
    double rho=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_srn = NULL;
    double srn=0;
    PyObject* pyobj_stn = NULL;
    double stn=0;
    PyObject* pyobj_min_theta = NULL;
    double min_theta=0;
    PyObject* pyobj_max_theta = NULL;
    double max_theta=CV_PI;

    const char* keywords[] = { "image", "rho", "theta", "threshold", "lines", "srn", "stn", "min_theta", "max_theta", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:HoughLines", (char**)keywords, &pyobj_image, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_lines, &pyobj_srn, &pyobj_stn, &pyobj_min_theta, &pyobj_max_theta) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_srn, srn, ArgInfo("srn", 0)) &&
        pyopencv_to(pyobj_stn, stn, ArgInfo("stn", 0)) &&
        pyopencv_to(pyobj_min_theta, min_theta, ArgInfo("min_theta", 0)) &&
        pyopencv_to(pyobj_max_theta, max_theta, ArgInfo("max_theta", 0)) )
    {
        ERRWRAP2(cv::HoughLines(image, lines, rho, theta, threshold, srn, stn, min_theta, max_theta));
        return pyopencv_from(lines);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_lines = NULL;
    UMat lines;
    PyObject* pyobj_rho = NULL;
    double rho=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_srn = NULL;
    double srn=0;
    PyObject* pyobj_stn = NULL;
    double stn=0;
    PyObject* pyobj_min_theta = NULL;
    double min_theta=0;
    PyObject* pyobj_max_theta = NULL;
    double max_theta=CV_PI;

    const char* keywords[] = { "image", "rho", "theta", "threshold", "lines", "srn", "stn", "min_theta", "max_theta", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:HoughLines", (char**)keywords, &pyobj_image, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_lines, &pyobj_srn, &pyobj_stn, &pyobj_min_theta, &pyobj_max_theta) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_srn, srn, ArgInfo("srn", 0)) &&
        pyopencv_to(pyobj_stn, stn, ArgInfo("stn", 0)) &&
        pyopencv_to(pyobj_min_theta, min_theta, ArgInfo("min_theta", 0)) &&
        pyopencv_to(pyobj_max_theta, max_theta, ArgInfo("max_theta", 0)) )
    {
        ERRWRAP2(cv::HoughLines(image, lines, rho, theta, threshold, srn, stn, min_theta, max_theta));
        return pyopencv_from(lines);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_HoughLinesP(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_lines = NULL;
    Mat lines;
    PyObject* pyobj_rho = NULL;
    double rho=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_minLineLength = NULL;
    double minLineLength=0;
    PyObject* pyobj_maxLineGap = NULL;
    double maxLineGap=0;

    const char* keywords[] = { "image", "rho", "theta", "threshold", "lines", "minLineLength", "maxLineGap", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:HoughLinesP", (char**)keywords, &pyobj_image, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_lines, &pyobj_minLineLength, &pyobj_maxLineGap) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_minLineLength, minLineLength, ArgInfo("minLineLength", 0)) &&
        pyopencv_to(pyobj_maxLineGap, maxLineGap, ArgInfo("maxLineGap", 0)) )
    {
        ERRWRAP2(cv::HoughLinesP(image, lines, rho, theta, threshold, minLineLength, maxLineGap));
        return pyopencv_from(lines);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_lines = NULL;
    UMat lines;
    PyObject* pyobj_rho = NULL;
    double rho=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_minLineLength = NULL;
    double minLineLength=0;
    PyObject* pyobj_maxLineGap = NULL;
    double maxLineGap=0;

    const char* keywords[] = { "image", "rho", "theta", "threshold", "lines", "minLineLength", "maxLineGap", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:HoughLinesP", (char**)keywords, &pyobj_image, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_lines, &pyobj_minLineLength, &pyobj_maxLineGap) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_minLineLength, minLineLength, ArgInfo("minLineLength", 0)) &&
        pyopencv_to(pyobj_maxLineGap, maxLineGap, ArgInfo("maxLineGap", 0)) )
    {
        ERRWRAP2(cv::HoughLinesP(image, lines, rho, theta, threshold, minLineLength, maxLineGap));
        return pyopencv_from(lines);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_HoughLinesPointSet(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj__point = NULL;
    Mat _point;
    PyObject* pyobj__lines = NULL;
    Mat _lines;
    PyObject* pyobj_lines_max = NULL;
    int lines_max=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_min_rho = NULL;
    double min_rho=0;
    PyObject* pyobj_max_rho = NULL;
    double max_rho=0;
    PyObject* pyobj_rho_step = NULL;
    double rho_step=0;
    PyObject* pyobj_min_theta = NULL;
    double min_theta=0;
    PyObject* pyobj_max_theta = NULL;
    double max_theta=0;
    PyObject* pyobj_theta_step = NULL;
    double theta_step=0;

    const char* keywords[] = { "_point", "lines_max", "threshold", "min_rho", "max_rho", "rho_step", "min_theta", "max_theta", "theta_step", "_lines", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOO|O:HoughLinesPointSet", (char**)keywords, &pyobj__point, &pyobj_lines_max, &pyobj_threshold, &pyobj_min_rho, &pyobj_max_rho, &pyobj_rho_step, &pyobj_min_theta, &pyobj_max_theta, &pyobj_theta_step, &pyobj__lines) &&
        pyopencv_to(pyobj__point, _point, ArgInfo("_point", 0)) &&
        pyopencv_to(pyobj__lines, _lines, ArgInfo("_lines", 1)) &&
        pyopencv_to(pyobj_lines_max, lines_max, ArgInfo("lines_max", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_min_rho, min_rho, ArgInfo("min_rho", 0)) &&
        pyopencv_to(pyobj_max_rho, max_rho, ArgInfo("max_rho", 0)) &&
        pyopencv_to(pyobj_rho_step, rho_step, ArgInfo("rho_step", 0)) &&
        pyopencv_to(pyobj_min_theta, min_theta, ArgInfo("min_theta", 0)) &&
        pyopencv_to(pyobj_max_theta, max_theta, ArgInfo("max_theta", 0)) &&
        pyopencv_to(pyobj_theta_step, theta_step, ArgInfo("theta_step", 0)) )
    {
        ERRWRAP2(cv::HoughLinesPointSet(_point, _lines, lines_max, threshold, min_rho, max_rho, rho_step, min_theta, max_theta, theta_step));
        return pyopencv_from(_lines);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj__point = NULL;
    UMat _point;
    PyObject* pyobj__lines = NULL;
    UMat _lines;
    PyObject* pyobj_lines_max = NULL;
    int lines_max=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_min_rho = NULL;
    double min_rho=0;
    PyObject* pyobj_max_rho = NULL;
    double max_rho=0;
    PyObject* pyobj_rho_step = NULL;
    double rho_step=0;
    PyObject* pyobj_min_theta = NULL;
    double min_theta=0;
    PyObject* pyobj_max_theta = NULL;
    double max_theta=0;
    PyObject* pyobj_theta_step = NULL;
    double theta_step=0;

    const char* keywords[] = { "_point", "lines_max", "threshold", "min_rho", "max_rho", "rho_step", "min_theta", "max_theta", "theta_step", "_lines", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOO|O:HoughLinesPointSet", (char**)keywords, &pyobj__point, &pyobj_lines_max, &pyobj_threshold, &pyobj_min_rho, &pyobj_max_rho, &pyobj_rho_step, &pyobj_min_theta, &pyobj_max_theta, &pyobj_theta_step, &pyobj__lines) &&
        pyopencv_to(pyobj__point, _point, ArgInfo("_point", 0)) &&
        pyopencv_to(pyobj__lines, _lines, ArgInfo("_lines", 1)) &&
        pyopencv_to(pyobj_lines_max, lines_max, ArgInfo("lines_max", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_min_rho, min_rho, ArgInfo("min_rho", 0)) &&
        pyopencv_to(pyobj_max_rho, max_rho, ArgInfo("max_rho", 0)) &&
        pyopencv_to(pyobj_rho_step, rho_step, ArgInfo("rho_step", 0)) &&
        pyopencv_to(pyobj_min_theta, min_theta, ArgInfo("min_theta", 0)) &&
        pyopencv_to(pyobj_max_theta, max_theta, ArgInfo("max_theta", 0)) &&
        pyopencv_to(pyobj_theta_step, theta_step, ArgInfo("theta_step", 0)) )
    {
        ERRWRAP2(cv::HoughLinesPointSet(_point, _lines, lines_max, threshold, min_rho, max_rho, rho_step, min_theta, max_theta, theta_step));
        return pyopencv_from(_lines);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_HuMoments(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_m = NULL;
    Moments m;
    PyObject* pyobj_hu = NULL;
    Mat hu;

    const char* keywords[] = { "m", "hu", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:HuMoments", (char**)keywords, &pyobj_m, &pyobj_hu) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to(pyobj_hu, hu, ArgInfo("hu", 1)) )
    {
        ERRWRAP2(cv::HuMoments(m, hu));
        return pyopencv_from(hu);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_m = NULL;
    Moments m;
    PyObject* pyobj_hu = NULL;
    UMat hu;

    const char* keywords[] = { "m", "hu", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:HuMoments", (char**)keywords, &pyobj_m, &pyobj_hu) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to(pyobj_hu, hu, ArgInfo("hu", 1)) )
    {
        ERRWRAP2(cv::HuMoments(m, hu));
        return pyopencv_from(hu);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_KAZE_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_extended = NULL;
    bool extended=false;
    PyObject* pyobj_upright = NULL;
    bool upright=false;
    PyObject* pyobj_threshold = NULL;
    float threshold=0.001f;
    PyObject* pyobj_nOctaves = NULL;
    int nOctaves=4;
    PyObject* pyobj_nOctaveLayers = NULL;
    int nOctaveLayers=4;
    PyObject* pyobj_diffusivity = NULL;
    KAZE_DiffusivityType diffusivity=KAZE::DIFF_PM_G2;
    Ptr<KAZE> retval;

    const char* keywords[] = { "extended", "upright", "threshold", "nOctaves", "nOctaveLayers", "diffusivity", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOOOO:KAZE_create", (char**)keywords, &pyobj_extended, &pyobj_upright, &pyobj_threshold, &pyobj_nOctaves, &pyobj_nOctaveLayers, &pyobj_diffusivity) &&
        pyopencv_to(pyobj_extended, extended, ArgInfo("extended", 0)) &&
        pyopencv_to(pyobj_upright, upright, ArgInfo("upright", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_nOctaves, nOctaves, ArgInfo("nOctaves", 0)) &&
        pyopencv_to(pyobj_nOctaveLayers, nOctaveLayers, ArgInfo("nOctaveLayers", 0)) &&
        pyopencv_to(pyobj_diffusivity, diffusivity, ArgInfo("diffusivity", 0)) )
    {
        ERRWRAP2(retval = cv::KAZE::create(extended, upright, threshold, nOctaves, nOctaveLayers, diffusivity));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_KeyPoint_convert(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_keypoints = NULL;
    vector_KeyPoint keypoints;
    vector_Point2f points2f;
    PyObject* pyobj_keypointIndexes = NULL;
    vector_int keypointIndexes=std::vector<int>();

    const char* keywords[] = { "keypoints", "keypointIndexes", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:KeyPoint_convert", (char**)keywords, &pyobj_keypoints, &pyobj_keypointIndexes) &&
        pyopencv_to(pyobj_keypoints, keypoints, ArgInfo("keypoints", 0)) &&
        pyopencv_to(pyobj_keypointIndexes, keypointIndexes, ArgInfo("keypointIndexes", 0)) )
    {
        ERRWRAP2(cv::KeyPoint::convert(keypoints, points2f, keypointIndexes));
        return pyopencv_from(points2f);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points2f = NULL;
    vector_Point2f points2f;
    vector_KeyPoint keypoints;
    PyObject* pyobj_size = NULL;
    float size=1;
    PyObject* pyobj_response = NULL;
    float response=1;
    PyObject* pyobj_octave = NULL;
    int octave=0;
    PyObject* pyobj_class_id = NULL;
    int class_id=-1;

    const char* keywords[] = { "points2f", "size", "response", "octave", "class_id", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:KeyPoint_convert", (char**)keywords, &pyobj_points2f, &pyobj_size, &pyobj_response, &pyobj_octave, &pyobj_class_id) &&
        pyopencv_to(pyobj_points2f, points2f, ArgInfo("points2f", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to(pyobj_response, response, ArgInfo("response", 0)) &&
        pyopencv_to(pyobj_octave, octave, ArgInfo("octave", 0)) &&
        pyopencv_to(pyobj_class_id, class_id, ArgInfo("class_id", 0)) )
    {
        ERRWRAP2(cv::KeyPoint::convert(points2f, keypoints, size, response, octave, class_id));
        return pyopencv_from(keypoints);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_KeyPoint_overlap(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_kp1 = NULL;
    KeyPoint kp1;
    PyObject* pyobj_kp2 = NULL;
    KeyPoint kp2;
    float retval;

    const char* keywords[] = { "kp1", "kp2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:KeyPoint_overlap", (char**)keywords, &pyobj_kp1, &pyobj_kp2) &&
        pyopencv_to(pyobj_kp1, kp1, ArgInfo("kp1", 0)) &&
        pyopencv_to(pyobj_kp2, kp2, ArgInfo("kp2", 0)) )
    {
        ERRWRAP2(retval = cv::KeyPoint::overlap(kp1, kp2));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_LUT(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_lut = NULL;
    Mat lut;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "lut", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:LUT", (char**)keywords, &pyobj_src, &pyobj_lut, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_lut, lut, ArgInfo("lut", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::LUT(src, lut, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_lut = NULL;
    UMat lut;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "lut", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:LUT", (char**)keywords, &pyobj_src, &pyobj_lut, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_lut, lut, ArgInfo("lut", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::LUT(src, lut, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_Laplacian(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=1;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dst", "ksize", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOO:Laplacian", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dst, &pyobj_ksize, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Laplacian(src, dst, ddepth, ksize, scale, delta, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=1;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dst", "ksize", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOO:Laplacian", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dst, &pyobj_ksize, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Laplacian(src, dst, ddepth, ksize, scale, delta, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_MSER_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj__delta = NULL;
    int _delta=5;
    PyObject* pyobj__min_area = NULL;
    int _min_area=60;
    PyObject* pyobj__max_area = NULL;
    int _max_area=14400;
    PyObject* pyobj__max_variation = NULL;
    double _max_variation=0.25;
    PyObject* pyobj__min_diversity = NULL;
    double _min_diversity=.2;
    PyObject* pyobj__max_evolution = NULL;
    int _max_evolution=200;
    PyObject* pyobj__area_threshold = NULL;
    double _area_threshold=1.01;
    PyObject* pyobj__min_margin = NULL;
    double _min_margin=0.003;
    PyObject* pyobj__edge_blur_size = NULL;
    int _edge_blur_size=5;
    Ptr<MSER> retval;

    const char* keywords[] = { "_delta", "_min_area", "_max_area", "_max_variation", "_min_diversity", "_max_evolution", "_area_threshold", "_min_margin", "_edge_blur_size", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOOOOOOO:MSER_create", (char**)keywords, &pyobj__delta, &pyobj__min_area, &pyobj__max_area, &pyobj__max_variation, &pyobj__min_diversity, &pyobj__max_evolution, &pyobj__area_threshold, &pyobj__min_margin, &pyobj__edge_blur_size) &&
        pyopencv_to(pyobj__delta, _delta, ArgInfo("_delta", 0)) &&
        pyopencv_to(pyobj__min_area, _min_area, ArgInfo("_min_area", 0)) &&
        pyopencv_to(pyobj__max_area, _max_area, ArgInfo("_max_area", 0)) &&
        pyopencv_to(pyobj__max_variation, _max_variation, ArgInfo("_max_variation", 0)) &&
        pyopencv_to(pyobj__min_diversity, _min_diversity, ArgInfo("_min_diversity", 0)) &&
        pyopencv_to(pyobj__max_evolution, _max_evolution, ArgInfo("_max_evolution", 0)) &&
        pyopencv_to(pyobj__area_threshold, _area_threshold, ArgInfo("_area_threshold", 0)) &&
        pyopencv_to(pyobj__min_margin, _min_margin, ArgInfo("_min_margin", 0)) &&
        pyopencv_to(pyobj__edge_blur_size, _edge_blur_size, ArgInfo("_edge_blur_size", 0)) )
    {
        ERRWRAP2(retval = cv::MSER::create(_delta, _min_area, _max_area, _max_variation, _min_diversity, _max_evolution, _area_threshold, _min_margin, _edge_blur_size));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Mahalanobis(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_v1 = NULL;
    Mat v1;
    PyObject* pyobj_v2 = NULL;
    Mat v2;
    PyObject* pyobj_icovar = NULL;
    Mat icovar;
    double retval;

    const char* keywords[] = { "v1", "v2", "icovar", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:Mahalanobis", (char**)keywords, &pyobj_v1, &pyobj_v2, &pyobj_icovar) &&
        pyopencv_to(pyobj_v1, v1, ArgInfo("v1", 0)) &&
        pyopencv_to(pyobj_v2, v2, ArgInfo("v2", 0)) &&
        pyopencv_to(pyobj_icovar, icovar, ArgInfo("icovar", 0)) )
    {
        ERRWRAP2(retval = cv::Mahalanobis(v1, v2, icovar));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_v1 = NULL;
    UMat v1;
    PyObject* pyobj_v2 = NULL;
    UMat v2;
    PyObject* pyobj_icovar = NULL;
    UMat icovar;
    double retval;

    const char* keywords[] = { "v1", "v2", "icovar", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:Mahalanobis", (char**)keywords, &pyobj_v1, &pyobj_v2, &pyobj_icovar) &&
        pyopencv_to(pyobj_v1, v1, ArgInfo("v1", 0)) &&
        pyopencv_to(pyobj_v2, v2, ArgInfo("v2", 0)) &&
        pyopencv_to(pyobj_icovar, icovar, ArgInfo("icovar", 0)) )
    {
        ERRWRAP2(retval = cv::Mahalanobis(v1, v2, icovar));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_ORB_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_nfeatures = NULL;
    int nfeatures=500;
    PyObject* pyobj_scaleFactor = NULL;
    float scaleFactor=1.2f;
    PyObject* pyobj_nlevels = NULL;
    int nlevels=8;
    PyObject* pyobj_edgeThreshold = NULL;
    int edgeThreshold=31;
    PyObject* pyobj_firstLevel = NULL;
    int firstLevel=0;
    PyObject* pyobj_WTA_K = NULL;
    int WTA_K=2;
    PyObject* pyobj_scoreType = NULL;
    ORB_ScoreType scoreType=ORB::HARRIS_SCORE;
    PyObject* pyobj_patchSize = NULL;
    int patchSize=31;
    PyObject* pyobj_fastThreshold = NULL;
    int fastThreshold=20;
    Ptr<ORB> retval;

    const char* keywords[] = { "nfeatures", "scaleFactor", "nlevels", "edgeThreshold", "firstLevel", "WTA_K", "scoreType", "patchSize", "fastThreshold", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOOOOOOO:ORB_create", (char**)keywords, &pyobj_nfeatures, &pyobj_scaleFactor, &pyobj_nlevels, &pyobj_edgeThreshold, &pyobj_firstLevel, &pyobj_WTA_K, &pyobj_scoreType, &pyobj_patchSize, &pyobj_fastThreshold) &&
        pyopencv_to(pyobj_nfeatures, nfeatures, ArgInfo("nfeatures", 0)) &&
        pyopencv_to(pyobj_scaleFactor, scaleFactor, ArgInfo("scaleFactor", 0)) &&
        pyopencv_to(pyobj_nlevels, nlevels, ArgInfo("nlevels", 0)) &&
        pyopencv_to(pyobj_edgeThreshold, edgeThreshold, ArgInfo("edgeThreshold", 0)) &&
        pyopencv_to(pyobj_firstLevel, firstLevel, ArgInfo("firstLevel", 0)) &&
        pyopencv_to(pyobj_WTA_K, WTA_K, ArgInfo("WTA_K", 0)) &&
        pyopencv_to(pyobj_scoreType, scoreType, ArgInfo("scoreType", 0)) &&
        pyopencv_to(pyobj_patchSize, patchSize, ArgInfo("patchSize", 0)) &&
        pyopencv_to(pyobj_fastThreshold, fastThreshold, ArgInfo("fastThreshold", 0)) )
    {
        ERRWRAP2(retval = cv::ORB::create(nfeatures, scaleFactor, nlevels, edgeThreshold, firstLevel, WTA_K, scoreType, patchSize, fastThreshold));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_PCABackProject(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_result = NULL;
    Mat result;

    const char* keywords[] = { "data", "mean", "eigenvectors", "result", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:PCABackProject", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_result) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 0)) &&
        pyopencv_to(pyobj_result, result, ArgInfo("result", 1)) )
    {
        ERRWRAP2(cv::PCABackProject(data, mean, eigenvectors, result));
        return pyopencv_from(result);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_result = NULL;
    UMat result;

    const char* keywords[] = { "data", "mean", "eigenvectors", "result", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:PCABackProject", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_result) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 0)) &&
        pyopencv_to(pyobj_result, result, ArgInfo("result", 1)) )
    {
        ERRWRAP2(cv::PCABackProject(data, mean, eigenvectors, result));
        return pyopencv_from(result);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_PCACompute(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_maxComponents = NULL;
    int maxComponents=0;

    const char* keywords[] = { "data", "mean", "eigenvectors", "maxComponents", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:PCACompute", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_maxComponents) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to(pyobj_maxComponents, maxComponents, ArgInfo("maxComponents", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, maxComponents));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(eigenvectors));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_maxComponents = NULL;
    int maxComponents=0;

    const char* keywords[] = { "data", "mean", "eigenvectors", "maxComponents", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:PCACompute", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_maxComponents) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to(pyobj_maxComponents, maxComponents, ArgInfo("maxComponents", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, maxComponents));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(eigenvectors));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_retainedVariance = NULL;
    double retainedVariance=0;

    const char* keywords[] = { "data", "mean", "retainedVariance", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:PCACompute", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_retainedVariance, &pyobj_eigenvectors) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to(pyobj_retainedVariance, retainedVariance, ArgInfo("retainedVariance", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, retainedVariance));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(eigenvectors));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_retainedVariance = NULL;
    double retainedVariance=0;

    const char* keywords[] = { "data", "mean", "retainedVariance", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:PCACompute", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_retainedVariance, &pyobj_eigenvectors) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to(pyobj_retainedVariance, retainedVariance, ArgInfo("retainedVariance", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, retainedVariance));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(eigenvectors));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_PCACompute2(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_eigenvalues = NULL;
    Mat eigenvalues;
    PyObject* pyobj_maxComponents = NULL;
    int maxComponents=0;

    const char* keywords[] = { "data", "mean", "eigenvectors", "eigenvalues", "maxComponents", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:PCACompute2", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_eigenvalues, &pyobj_maxComponents) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to(pyobj_maxComponents, maxComponents, ArgInfo("maxComponents", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, eigenvalues, maxComponents));
        return Py_BuildValue("(NNN)", pyopencv_from(mean), pyopencv_from(eigenvectors), pyopencv_from(eigenvalues));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_eigenvalues = NULL;
    UMat eigenvalues;
    PyObject* pyobj_maxComponents = NULL;
    int maxComponents=0;

    const char* keywords[] = { "data", "mean", "eigenvectors", "eigenvalues", "maxComponents", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:PCACompute2", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_eigenvalues, &pyobj_maxComponents) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to(pyobj_maxComponents, maxComponents, ArgInfo("maxComponents", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, eigenvalues, maxComponents));
        return Py_BuildValue("(NNN)", pyopencv_from(mean), pyopencv_from(eigenvectors), pyopencv_from(eigenvalues));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_eigenvalues = NULL;
    Mat eigenvalues;
    PyObject* pyobj_retainedVariance = NULL;
    double retainedVariance=0;

    const char* keywords[] = { "data", "mean", "retainedVariance", "eigenvectors", "eigenvalues", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:PCACompute2", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_retainedVariance, &pyobj_eigenvectors, &pyobj_eigenvalues) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to(pyobj_retainedVariance, retainedVariance, ArgInfo("retainedVariance", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, eigenvalues, retainedVariance));
        return Py_BuildValue("(NNN)", pyopencv_from(mean), pyopencv_from(eigenvectors), pyopencv_from(eigenvalues));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_eigenvalues = NULL;
    UMat eigenvalues;
    PyObject* pyobj_retainedVariance = NULL;
    double retainedVariance=0;

    const char* keywords[] = { "data", "mean", "retainedVariance", "eigenvectors", "eigenvalues", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:PCACompute2", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_retainedVariance, &pyobj_eigenvectors, &pyobj_eigenvalues) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to(pyobj_retainedVariance, retainedVariance, ArgInfo("retainedVariance", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, eigenvalues, retainedVariance));
        return Py_BuildValue("(NNN)", pyopencv_from(mean), pyopencv_from(eigenvectors), pyopencv_from(eigenvalues));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_PCAProject(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_result = NULL;
    Mat result;

    const char* keywords[] = { "data", "mean", "eigenvectors", "result", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:PCAProject", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_result) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 0)) &&
        pyopencv_to(pyobj_result, result, ArgInfo("result", 1)) )
    {
        ERRWRAP2(cv::PCAProject(data, mean, eigenvectors, result));
        return pyopencv_from(result);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_result = NULL;
    UMat result;

    const char* keywords[] = { "data", "mean", "eigenvectors", "result", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:PCAProject", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_result) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 0)) &&
        pyopencv_to(pyobj_result, result, ArgInfo("result", 1)) )
    {
        ERRWRAP2(cv::PCAProject(data, mean, eigenvectors, result));
        return pyopencv_from(result);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_PSNR(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_R = NULL;
    double R=255.;
    double retval;

    const char* keywords[] = { "src1", "src2", "R", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:PSNR", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_R) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) )
    {
        ERRWRAP2(retval = cv::PSNR(src1, src2, R));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_R = NULL;
    double R=255.;
    double retval;

    const char* keywords[] = { "src1", "src2", "R", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:PSNR", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_R) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) )
    {
        ERRWRAP2(retval = cv::PSNR(src1, src2, R));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_RQDecomp3x3(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mtxR = NULL;
    Mat mtxR;
    PyObject* pyobj_mtxQ = NULL;
    Mat mtxQ;
    PyObject* pyobj_Qx = NULL;
    Mat Qx;
    PyObject* pyobj_Qy = NULL;
    Mat Qy;
    PyObject* pyobj_Qz = NULL;
    Mat Qz;
    Vec3d retval;

    const char* keywords[] = { "src", "mtxR", "mtxQ", "Qx", "Qy", "Qz", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOO:RQDecomp3x3", (char**)keywords, &pyobj_src, &pyobj_mtxR, &pyobj_mtxQ, &pyobj_Qx, &pyobj_Qy, &pyobj_Qz) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mtxR, mtxR, ArgInfo("mtxR", 1)) &&
        pyopencv_to(pyobj_mtxQ, mtxQ, ArgInfo("mtxQ", 1)) &&
        pyopencv_to(pyobj_Qx, Qx, ArgInfo("Qx", 1)) &&
        pyopencv_to(pyobj_Qy, Qy, ArgInfo("Qy", 1)) &&
        pyopencv_to(pyobj_Qz, Qz, ArgInfo("Qz", 1)) )
    {
        ERRWRAP2(retval = cv::RQDecomp3x3(src, mtxR, mtxQ, Qx, Qy, Qz));
        return Py_BuildValue("(NNNNNN)", pyopencv_from(retval), pyopencv_from(mtxR), pyopencv_from(mtxQ), pyopencv_from(Qx), pyopencv_from(Qy), pyopencv_from(Qz));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mtxR = NULL;
    UMat mtxR;
    PyObject* pyobj_mtxQ = NULL;
    UMat mtxQ;
    PyObject* pyobj_Qx = NULL;
    UMat Qx;
    PyObject* pyobj_Qy = NULL;
    UMat Qy;
    PyObject* pyobj_Qz = NULL;
    UMat Qz;
    Vec3d retval;

    const char* keywords[] = { "src", "mtxR", "mtxQ", "Qx", "Qy", "Qz", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOO:RQDecomp3x3", (char**)keywords, &pyobj_src, &pyobj_mtxR, &pyobj_mtxQ, &pyobj_Qx, &pyobj_Qy, &pyobj_Qz) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mtxR, mtxR, ArgInfo("mtxR", 1)) &&
        pyopencv_to(pyobj_mtxQ, mtxQ, ArgInfo("mtxQ", 1)) &&
        pyopencv_to(pyobj_Qx, Qx, ArgInfo("Qx", 1)) &&
        pyopencv_to(pyobj_Qy, Qy, ArgInfo("Qy", 1)) &&
        pyopencv_to(pyobj_Qz, Qz, ArgInfo("Qz", 1)) )
    {
        ERRWRAP2(retval = cv::RQDecomp3x3(src, mtxR, mtxQ, Qx, Qy, Qz));
        return Py_BuildValue("(NNNNNN)", pyopencv_from(retval), pyopencv_from(mtxR), pyopencv_from(mtxQ), pyopencv_from(Qx), pyopencv_from(Qy), pyopencv_from(Qz));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_Rodrigues(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_jacobian = NULL;
    Mat jacobian;

    const char* keywords[] = { "src", "dst", "jacobian", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:Rodrigues", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_jacobian) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_jacobian, jacobian, ArgInfo("jacobian", 1)) )
    {
        ERRWRAP2(cv::Rodrigues(src, dst, jacobian));
        return Py_BuildValue("(NN)", pyopencv_from(dst), pyopencv_from(jacobian));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_jacobian = NULL;
    UMat jacobian;

    const char* keywords[] = { "src", "dst", "jacobian", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:Rodrigues", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_jacobian) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_jacobian, jacobian, ArgInfo("jacobian", 1)) )
    {
        ERRWRAP2(cv::Rodrigues(src, dst, jacobian));
        return Py_BuildValue("(NN)", pyopencv_from(dst), pyopencv_from(jacobian));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_SVBackSubst(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_w = NULL;
    Mat w;
    PyObject* pyobj_u = NULL;
    Mat u;
    PyObject* pyobj_vt = NULL;
    Mat vt;
    PyObject* pyobj_rhs = NULL;
    Mat rhs;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "w", "u", "vt", "rhs", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:SVBackSubst", (char**)keywords, &pyobj_w, &pyobj_u, &pyobj_vt, &pyobj_rhs, &pyobj_dst) &&
        pyopencv_to(pyobj_w, w, ArgInfo("w", 0)) &&
        pyopencv_to(pyobj_u, u, ArgInfo("u", 0)) &&
        pyopencv_to(pyobj_vt, vt, ArgInfo("vt", 0)) &&
        pyopencv_to(pyobj_rhs, rhs, ArgInfo("rhs", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::SVBackSubst(w, u, vt, rhs, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_w = NULL;
    UMat w;
    PyObject* pyobj_u = NULL;
    UMat u;
    PyObject* pyobj_vt = NULL;
    UMat vt;
    PyObject* pyobj_rhs = NULL;
    UMat rhs;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "w", "u", "vt", "rhs", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:SVBackSubst", (char**)keywords, &pyobj_w, &pyobj_u, &pyobj_vt, &pyobj_rhs, &pyobj_dst) &&
        pyopencv_to(pyobj_w, w, ArgInfo("w", 0)) &&
        pyopencv_to(pyobj_u, u, ArgInfo("u", 0)) &&
        pyopencv_to(pyobj_vt, vt, ArgInfo("vt", 0)) &&
        pyopencv_to(pyobj_rhs, rhs, ArgInfo("rhs", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::SVBackSubst(w, u, vt, rhs, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_SVDecomp(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_w = NULL;
    Mat w;
    PyObject* pyobj_u = NULL;
    Mat u;
    PyObject* pyobj_vt = NULL;
    Mat vt;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "w", "u", "vt", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:SVDecomp", (char**)keywords, &pyobj_src, &pyobj_w, &pyobj_u, &pyobj_vt, &pyobj_flags) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_w, w, ArgInfo("w", 1)) &&
        pyopencv_to(pyobj_u, u, ArgInfo("u", 1)) &&
        pyopencv_to(pyobj_vt, vt, ArgInfo("vt", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::SVDecomp(src, w, u, vt, flags));
        return Py_BuildValue("(NNN)", pyopencv_from(w), pyopencv_from(u), pyopencv_from(vt));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_w = NULL;
    UMat w;
    PyObject* pyobj_u = NULL;
    UMat u;
    PyObject* pyobj_vt = NULL;
    UMat vt;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "w", "u", "vt", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:SVDecomp", (char**)keywords, &pyobj_src, &pyobj_w, &pyobj_u, &pyobj_vt, &pyobj_flags) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_w, w, ArgInfo("w", 1)) &&
        pyopencv_to(pyobj_u, u, ArgInfo("u", 1)) &&
        pyopencv_to(pyobj_vt, vt, ArgInfo("vt", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::SVDecomp(src, w, u, vt, flags));
        return Py_BuildValue("(NNN)", pyopencv_from(w), pyopencv_from(u), pyopencv_from(vt));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_Scharr(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dx", "dy", "dst", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:Scharr", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dx, &pyobj_dy, &pyobj_dst, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Scharr(src, dst, ddepth, dx, dy, scale, delta, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dx", "dy", "dst", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:Scharr", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dx, &pyobj_dy, &pyobj_dst, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Scharr(src, dst, ddepth, dx, dy, scale, delta, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_SimpleBlobDetector_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_parameters = NULL;
    SimpleBlobDetector_Params parameters=SimpleBlobDetector::Params();
    Ptr<SimpleBlobDetector> retval;

    const char* keywords[] = { "parameters", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|O:SimpleBlobDetector_create", (char**)keywords, &pyobj_parameters) &&
        pyopencv_to(pyobj_parameters, parameters, ArgInfo("parameters", 0)) )
    {
        ERRWRAP2(retval = cv::SimpleBlobDetector::create(parameters));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Sobel(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dx", "dy", "dst", "ksize", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:Sobel", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dx, &pyobj_dy, &pyobj_dst, &pyobj_ksize, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Sobel(src, dst, ddepth, dx, dy, ksize, scale, delta, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dx", "dy", "dst", "ksize", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:Sobel", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dx, &pyobj_dy, &pyobj_dst, &pyobj_ksize, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Sobel(src, dst, ddepth, dx, dy, ksize, scale, delta, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_SparsePyrLKOpticalFlow_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_winSize = NULL;
    Size winSize=Size(21, 21);
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=3;
    PyObject* pyobj_crit = NULL;
    TermCriteria crit=TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 0.01);
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_minEigThreshold = NULL;
    double minEigThreshold=1e-4;
    Ptr<SparsePyrLKOpticalFlow> retval;

    const char* keywords[] = { "winSize", "maxLevel", "crit", "flags", "minEigThreshold", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOOO:SparsePyrLKOpticalFlow_create", (char**)keywords, &pyobj_winSize, &pyobj_maxLevel, &pyobj_crit, &pyobj_flags, &pyobj_minEigThreshold) &&
        pyopencv_to(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to(pyobj_crit, crit, ArgInfo("crit", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_minEigThreshold, minEigThreshold, ArgInfo("minEigThreshold", 0)) )
    {
        ERRWRAP2(retval = cv::SparsePyrLKOpticalFlow::create(winSize, maxLevel, crit, flags, minEigThreshold));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_StereoBM_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_numDisparities = NULL;
    int numDisparities=0;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=21;
    Ptr<StereoBM> retval;

    const char* keywords[] = { "numDisparities", "blockSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OO:StereoBM_create", (char**)keywords, &pyobj_numDisparities, &pyobj_blockSize) &&
        pyopencv_to(pyobj_numDisparities, numDisparities, ArgInfo("numDisparities", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) )
    {
        ERRWRAP2(retval = cv::StereoBM::create(numDisparities, blockSize));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_StereoSGBM_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_minDisparity = NULL;
    int minDisparity=0;
    PyObject* pyobj_numDisparities = NULL;
    int numDisparities=16;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=3;
    PyObject* pyobj_P1 = NULL;
    int P1=0;
    PyObject* pyobj_P2 = NULL;
    int P2=0;
    PyObject* pyobj_disp12MaxDiff = NULL;
    int disp12MaxDiff=0;
    PyObject* pyobj_preFilterCap = NULL;
    int preFilterCap=0;
    PyObject* pyobj_uniquenessRatio = NULL;
    int uniquenessRatio=0;
    PyObject* pyobj_speckleWindowSize = NULL;
    int speckleWindowSize=0;
    PyObject* pyobj_speckleRange = NULL;
    int speckleRange=0;
    PyObject* pyobj_mode = NULL;
    int mode=StereoSGBM::MODE_SGBM;
    Ptr<StereoSGBM> retval;

    const char* keywords[] = { "minDisparity", "numDisparities", "blockSize", "P1", "P2", "disp12MaxDiff", "preFilterCap", "uniquenessRatio", "speckleWindowSize", "speckleRange", "mode", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOOOOOOOOO:StereoSGBM_create", (char**)keywords, &pyobj_minDisparity, &pyobj_numDisparities, &pyobj_blockSize, &pyobj_P1, &pyobj_P2, &pyobj_disp12MaxDiff, &pyobj_preFilterCap, &pyobj_uniquenessRatio, &pyobj_speckleWindowSize, &pyobj_speckleRange, &pyobj_mode) &&
        pyopencv_to(pyobj_minDisparity, minDisparity, ArgInfo("minDisparity", 0)) &&
        pyopencv_to(pyobj_numDisparities, numDisparities, ArgInfo("numDisparities", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_P1, P1, ArgInfo("P1", 0)) &&
        pyopencv_to(pyobj_P2, P2, ArgInfo("P2", 0)) &&
        pyopencv_to(pyobj_disp12MaxDiff, disp12MaxDiff, ArgInfo("disp12MaxDiff", 0)) &&
        pyopencv_to(pyobj_preFilterCap, preFilterCap, ArgInfo("preFilterCap", 0)) &&
        pyopencv_to(pyobj_uniquenessRatio, uniquenessRatio, ArgInfo("uniquenessRatio", 0)) &&
        pyopencv_to(pyobj_speckleWindowSize, speckleWindowSize, ArgInfo("speckleWindowSize", 0)) &&
        pyopencv_to(pyobj_speckleRange, speckleRange, ArgInfo("speckleRange", 0)) &&
        pyopencv_to(pyobj_mode, mode, ArgInfo("mode", 0)) )
    {
        ERRWRAP2(retval = cv::StereoSGBM::create(minDisparity, numDisparities, blockSize, P1, P2, disp12MaxDiff, preFilterCap, uniquenessRatio, speckleWindowSize, speckleRange, mode));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Stitcher_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_mode = NULL;
    Mode mode=Stitcher::PANORAMA;
    Ptr<Stitcher> retval;

    const char* keywords[] = { "mode", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|O:Stitcher_create", (char**)keywords, &pyobj_mode) &&
        pyopencv_to(pyobj_mode, mode, ArgInfo("mode", 0)) )
    {
        ERRWRAP2(retval = cv::Stitcher::create(mode));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_context(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    void* retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_context());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_queue(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    void* retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_queue());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VariationalRefinement_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    Ptr<VariationalRefinement> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::VariationalRefinement::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoWriter_fourcc(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_c1 = NULL;
    char c1;
    PyObject* pyobj_c2 = NULL;
    char c2;
    PyObject* pyobj_c3 = NULL;
    char c3;
    PyObject* pyobj_c4 = NULL;
    char c4;
    int retval;

    const char* keywords[] = { "c1", "c2", "c3", "c4", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO:VideoWriter_fourcc", (char**)keywords, &pyobj_c1, &pyobj_c2, &pyobj_c3, &pyobj_c4) &&
        convert_to_char(pyobj_c1, &c1, ArgInfo("c1", 0)) &&
        convert_to_char(pyobj_c2, &c2, ArgInfo("c2", 0)) &&
        convert_to_char(pyobj_c3, &c3, ArgInfo("c3", 0)) &&
        convert_to_char(pyobj_c4, &c4, ArgInfo("c4", 0)) )
    {
        ERRWRAP2(retval = cv::VideoWriter::fourcc(c1, c2, c3, c4));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_absdiff(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:absdiff", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::absdiff(src1, src2, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:absdiff", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::absdiff(src1, src2, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_accumulate(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:accumulate", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulate(src, dst, mask));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:accumulate", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulate(src, dst, mask));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_accumulateProduct(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:accumulateProduct", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateProduct(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:accumulateProduct", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateProduct(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_accumulateSquare(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:accumulateSquare", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateSquare(src, dst, mask));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:accumulateSquare", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateSquare(src, dst, mask));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_accumulateWeighted(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "dst", "alpha", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:accumulateWeighted", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateWeighted(src, dst, alpha, mask));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "dst", "alpha", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:accumulateWeighted", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateWeighted(src, dst, alpha, mask));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_adaptiveThreshold(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_maxValue = NULL;
    double maxValue=0;
    PyObject* pyobj_adaptiveMethod = NULL;
    int adaptiveMethod=0;
    PyObject* pyobj_thresholdType = NULL;
    int thresholdType=0;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_C = NULL;
    double C=0;

    const char* keywords[] = { "src", "maxValue", "adaptiveMethod", "thresholdType", "blockSize", "C", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:adaptiveThreshold", (char**)keywords, &pyobj_src, &pyobj_maxValue, &pyobj_adaptiveMethod, &pyobj_thresholdType, &pyobj_blockSize, &pyobj_C, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_maxValue, maxValue, ArgInfo("maxValue", 0)) &&
        pyopencv_to(pyobj_adaptiveMethod, adaptiveMethod, ArgInfo("adaptiveMethod", 0)) &&
        pyopencv_to(pyobj_thresholdType, thresholdType, ArgInfo("thresholdType", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_C, C, ArgInfo("C", 0)) )
    {
        ERRWRAP2(cv::adaptiveThreshold(src, dst, maxValue, adaptiveMethod, thresholdType, blockSize, C));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_maxValue = NULL;
    double maxValue=0;
    PyObject* pyobj_adaptiveMethod = NULL;
    int adaptiveMethod=0;
    PyObject* pyobj_thresholdType = NULL;
    int thresholdType=0;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_C = NULL;
    double C=0;

    const char* keywords[] = { "src", "maxValue", "adaptiveMethod", "thresholdType", "blockSize", "C", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:adaptiveThreshold", (char**)keywords, &pyobj_src, &pyobj_maxValue, &pyobj_adaptiveMethod, &pyobj_thresholdType, &pyobj_blockSize, &pyobj_C, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_maxValue, maxValue, ArgInfo("maxValue", 0)) &&
        pyopencv_to(pyobj_adaptiveMethod, adaptiveMethod, ArgInfo("adaptiveMethod", 0)) &&
        pyopencv_to(pyobj_thresholdType, thresholdType, ArgInfo("thresholdType", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_C, C, ArgInfo("C", 0)) )
    {
        ERRWRAP2(cv::adaptiveThreshold(src, dst, maxValue, adaptiveMethod, thresholdType, blockSize, C));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_add(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:add", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::add(src1, src2, dst, mask, dtype));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:add", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::add(src1, src2, dst, mask, dtype));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_addText(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_text = NULL;
    String text;
    PyObject* pyobj_org = NULL;
    Point org;
    PyObject* pyobj_nameFont = NULL;
    String nameFont;
    PyObject* pyobj_pointSize = NULL;
    int pointSize=-1;
    PyObject* pyobj_color = NULL;
    Scalar color=Scalar::all(0);
    PyObject* pyobj_weight = NULL;
    int weight=QT_FONT_NORMAL;
    PyObject* pyobj_style = NULL;
    int style=QT_STYLE_NORMAL;
    PyObject* pyobj_spacing = NULL;
    int spacing=0;

    const char* keywords[] = { "img", "text", "org", "nameFont", "pointSize", "color", "weight", "style", "spacing", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:addText", (char**)keywords, &pyobj_img, &pyobj_text, &pyobj_org, &pyobj_nameFont, &pyobj_pointSize, &pyobj_color, &pyobj_weight, &pyobj_style, &pyobj_spacing) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_text, text, ArgInfo("text", 0)) &&
        pyopencv_to(pyobj_org, org, ArgInfo("org", 0)) &&
        pyopencv_to(pyobj_nameFont, nameFont, ArgInfo("nameFont", 0)) &&
        pyopencv_to(pyobj_pointSize, pointSize, ArgInfo("pointSize", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_weight, weight, ArgInfo("weight", 0)) &&
        pyopencv_to(pyobj_style, style, ArgInfo("style", 0)) &&
        pyopencv_to(pyobj_spacing, spacing, ArgInfo("spacing", 0)) )
    {
        ERRWRAP2(cv::addText(img, text, org, nameFont, pointSize, color, weight, style, spacing));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_text = NULL;
    String text;
    PyObject* pyobj_org = NULL;
    Point org;
    PyObject* pyobj_nameFont = NULL;
    String nameFont;
    PyObject* pyobj_pointSize = NULL;
    int pointSize=-1;
    PyObject* pyobj_color = NULL;
    Scalar color=Scalar::all(0);
    PyObject* pyobj_weight = NULL;
    int weight=QT_FONT_NORMAL;
    PyObject* pyobj_style = NULL;
    int style=QT_STYLE_NORMAL;
    PyObject* pyobj_spacing = NULL;
    int spacing=0;

    const char* keywords[] = { "img", "text", "org", "nameFont", "pointSize", "color", "weight", "style", "spacing", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:addText", (char**)keywords, &pyobj_img, &pyobj_text, &pyobj_org, &pyobj_nameFont, &pyobj_pointSize, &pyobj_color, &pyobj_weight, &pyobj_style, &pyobj_spacing) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_text, text, ArgInfo("text", 0)) &&
        pyopencv_to(pyobj_org, org, ArgInfo("org", 0)) &&
        pyopencv_to(pyobj_nameFont, nameFont, ArgInfo("nameFont", 0)) &&
        pyopencv_to(pyobj_pointSize, pointSize, ArgInfo("pointSize", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_weight, weight, ArgInfo("weight", 0)) &&
        pyopencv_to(pyobj_style, style, ArgInfo("style", 0)) &&
        pyopencv_to(pyobj_spacing, spacing, ArgInfo("spacing", 0)) )
    {
        ERRWRAP2(cv::addText(img, text, org, nameFont, pointSize, color, weight, style, spacing));
        Py_RETURN_NONE;
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_addWeighted(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_gamma = NULL;
    double gamma=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "alpha", "src2", "beta", "gamma", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OO:addWeighted", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_beta, &pyobj_gamma, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::addWeighted(src1, alpha, src2, beta, gamma, dst, dtype));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_gamma = NULL;
    double gamma=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "alpha", "src2", "beta", "gamma", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OO:addWeighted", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_beta, &pyobj_gamma, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::addWeighted(src1, alpha, src2, beta, gamma, dst, dtype));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_applyColorMap(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_colormap = NULL;
    int colormap=0;

    const char* keywords[] = { "src", "colormap", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:applyColorMap", (char**)keywords, &pyobj_src, &pyobj_colormap, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_colormap, colormap, ArgInfo("colormap", 0)) )
    {
        ERRWRAP2(cv::applyColorMap(src, dst, colormap));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_colormap = NULL;
    int colormap=0;

    const char* keywords[] = { "src", "colormap", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:applyColorMap", (char**)keywords, &pyobj_src, &pyobj_colormap, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_colormap, colormap, ArgInfo("colormap", 0)) )
    {
        ERRWRAP2(cv::applyColorMap(src, dst, colormap));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_userColor = NULL;
    Mat userColor;

    const char* keywords[] = { "src", "userColor", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:applyColorMap", (char**)keywords, &pyobj_src, &pyobj_userColor, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_userColor, userColor, ArgInfo("userColor", 0)) )
    {
        ERRWRAP2(cv::applyColorMap(src, dst, userColor));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_userColor = NULL;
    UMat userColor;

    const char* keywords[] = { "src", "userColor", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:applyColorMap", (char**)keywords, &pyobj_src, &pyobj_userColor, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_userColor, userColor, ArgInfo("userColor", 0)) )
    {
        ERRWRAP2(cv::applyColorMap(src, dst, userColor));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_approxPolyDP(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_curve = NULL;
    Mat curve;
    PyObject* pyobj_approxCurve = NULL;
    Mat approxCurve;
    PyObject* pyobj_epsilon = NULL;
    double epsilon=0;
    PyObject* pyobj_closed = NULL;
    bool closed=0;

    const char* keywords[] = { "curve", "epsilon", "closed", "approxCurve", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:approxPolyDP", (char**)keywords, &pyobj_curve, &pyobj_epsilon, &pyobj_closed, &pyobj_approxCurve) &&
        pyopencv_to(pyobj_curve, curve, ArgInfo("curve", 0)) &&
        pyopencv_to(pyobj_approxCurve, approxCurve, ArgInfo("approxCurve", 1)) &&
        pyopencv_to(pyobj_epsilon, epsilon, ArgInfo("epsilon", 0)) &&
        pyopencv_to(pyobj_closed, closed, ArgInfo("closed", 0)) )
    {
        ERRWRAP2(cv::approxPolyDP(curve, approxCurve, epsilon, closed));
        return pyopencv_from(approxCurve);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_curve = NULL;
    UMat curve;
    PyObject* pyobj_approxCurve = NULL;
    UMat approxCurve;
    PyObject* pyobj_epsilon = NULL;
    double epsilon=0;
    PyObject* pyobj_closed = NULL;
    bool closed=0;

    const char* keywords[] = { "curve", "epsilon", "closed", "approxCurve", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:approxPolyDP", (char**)keywords, &pyobj_curve, &pyobj_epsilon, &pyobj_closed, &pyobj_approxCurve) &&
        pyopencv_to(pyobj_curve, curve, ArgInfo("curve", 0)) &&
        pyopencv_to(pyobj_approxCurve, approxCurve, ArgInfo("approxCurve", 1)) &&
        pyopencv_to(pyobj_epsilon, epsilon, ArgInfo("epsilon", 0)) &&
        pyopencv_to(pyobj_closed, closed, ArgInfo("closed", 0)) )
    {
        ERRWRAP2(cv::approxPolyDP(curve, approxCurve, epsilon, closed));
        return pyopencv_from(approxCurve);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_arcLength(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_curve = NULL;
    Mat curve;
    PyObject* pyobj_closed = NULL;
    bool closed=0;
    double retval;

    const char* keywords[] = { "curve", "closed", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:arcLength", (char**)keywords, &pyobj_curve, &pyobj_closed) &&
        pyopencv_to(pyobj_curve, curve, ArgInfo("curve", 0)) &&
        pyopencv_to(pyobj_closed, closed, ArgInfo("closed", 0)) )
    {
        ERRWRAP2(retval = cv::arcLength(curve, closed));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_curve = NULL;
    UMat curve;
    PyObject* pyobj_closed = NULL;
    bool closed=0;
    double retval;

    const char* keywords[] = { "curve", "closed", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:arcLength", (char**)keywords, &pyobj_curve, &pyobj_closed) &&
        pyopencv_to(pyobj_curve, curve, ArgInfo("curve", 0)) &&
        pyopencv_to(pyobj_closed, closed, ArgInfo("closed", 0)) )
    {
        ERRWRAP2(retval = cv::arcLength(curve, closed));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_arrowedLine(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_line_type = NULL;
    int line_type=8;
    PyObject* pyobj_shift = NULL;
    int shift=0;
    PyObject* pyobj_tipLength = NULL;
    double tipLength=0.1;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "line_type", "shift", "tipLength", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:arrowedLine", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_line_type, &pyobj_shift, &pyobj_tipLength) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_line_type, line_type, ArgInfo("line_type", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) &&
        pyopencv_to(pyobj_tipLength, tipLength, ArgInfo("tipLength", 0)) )
    {
        ERRWRAP2(cv::arrowedLine(img, pt1, pt2, color, thickness, line_type, shift, tipLength));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_line_type = NULL;
    int line_type=8;
    PyObject* pyobj_shift = NULL;
    int shift=0;
    PyObject* pyobj_tipLength = NULL;
    double tipLength=0.1;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "line_type", "shift", "tipLength", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:arrowedLine", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_line_type, &pyobj_shift, &pyobj_tipLength) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_line_type, line_type, ArgInfo("line_type", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) &&
        pyopencv_to(pyobj_tipLength, tipLength, ArgInfo("tipLength", 0)) )
    {
        ERRWRAP2(cv::arrowedLine(img, pt1, pt2, color, thickness, line_type, shift, tipLength));
        return pyopencv_from(img);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_batchDistance(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dist = NULL;
    Mat dist;
    PyObject* pyobj_dtype = NULL;
    int dtype=0;
    PyObject* pyobj_nidx = NULL;
    Mat nidx;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_K = NULL;
    int K=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_update = NULL;
    int update=0;
    PyObject* pyobj_crosscheck = NULL;
    bool crosscheck=false;

    const char* keywords[] = { "src1", "src2", "dtype", "dist", "nidx", "normType", "K", "mask", "update", "crosscheck", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOOOOO:batchDistance", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dtype, &pyobj_dist, &pyobj_nidx, &pyobj_normType, &pyobj_K, &pyobj_mask, &pyobj_update, &pyobj_crosscheck) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dist, dist, ArgInfo("dist", 1)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to(pyobj_nidx, nidx, ArgInfo("nidx", 1)) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_update, update, ArgInfo("update", 0)) &&
        pyopencv_to(pyobj_crosscheck, crosscheck, ArgInfo("crosscheck", 0)) )
    {
        ERRWRAP2(cv::batchDistance(src1, src2, dist, dtype, nidx, normType, K, mask, update, crosscheck));
        return Py_BuildValue("(NN)", pyopencv_from(dist), pyopencv_from(nidx));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dist = NULL;
    UMat dist;
    PyObject* pyobj_dtype = NULL;
    int dtype=0;
    PyObject* pyobj_nidx = NULL;
    UMat nidx;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_K = NULL;
    int K=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_update = NULL;
    int update=0;
    PyObject* pyobj_crosscheck = NULL;
    bool crosscheck=false;

    const char* keywords[] = { "src1", "src2", "dtype", "dist", "nidx", "normType", "K", "mask", "update", "crosscheck", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOOOOO:batchDistance", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dtype, &pyobj_dist, &pyobj_nidx, &pyobj_normType, &pyobj_K, &pyobj_mask, &pyobj_update, &pyobj_crosscheck) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dist, dist, ArgInfo("dist", 1)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to(pyobj_nidx, nidx, ArgInfo("nidx", 1)) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_update, update, ArgInfo("update", 0)) &&
        pyopencv_to(pyobj_crosscheck, crosscheck, ArgInfo("crosscheck", 0)) )
    {
        ERRWRAP2(cv::batchDistance(src1, src2, dist, dtype, nidx, normType, K, mask, update, crosscheck));
        return Py_BuildValue("(NN)", pyopencv_from(dist), pyopencv_from(nidx));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_bilateralFilter(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_d = NULL;
    int d=0;
    PyObject* pyobj_sigmaColor = NULL;
    double sigmaColor=0;
    PyObject* pyobj_sigmaSpace = NULL;
    double sigmaSpace=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "d", "sigmaColor", "sigmaSpace", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:bilateralFilter", (char**)keywords, &pyobj_src, &pyobj_d, &pyobj_sigmaColor, &pyobj_sigmaSpace, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_d, d, ArgInfo("d", 0)) &&
        pyopencv_to(pyobj_sigmaColor, sigmaColor, ArgInfo("sigmaColor", 0)) &&
        pyopencv_to(pyobj_sigmaSpace, sigmaSpace, ArgInfo("sigmaSpace", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::bilateralFilter(src, dst, d, sigmaColor, sigmaSpace, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_d = NULL;
    int d=0;
    PyObject* pyobj_sigmaColor = NULL;
    double sigmaColor=0;
    PyObject* pyobj_sigmaSpace = NULL;
    double sigmaSpace=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "d", "sigmaColor", "sigmaSpace", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:bilateralFilter", (char**)keywords, &pyobj_src, &pyobj_d, &pyobj_sigmaColor, &pyobj_sigmaSpace, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_d, d, ArgInfo("d", 0)) &&
        pyopencv_to(pyobj_sigmaColor, sigmaColor, ArgInfo("sigmaColor", 0)) &&
        pyopencv_to(pyobj_sigmaSpace, sigmaSpace, ArgInfo("sigmaSpace", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::bilateralFilter(src, dst, d, sigmaColor, sigmaSpace, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_bitwise_and(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:bitwise_and", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_and(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:bitwise_and", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_and(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_bitwise_not(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:bitwise_not", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_not(src, dst, mask));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:bitwise_not", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_not(src, dst, mask));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_bitwise_or(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:bitwise_or", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_or(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:bitwise_or", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_or(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_bitwise_xor(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:bitwise_xor", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_xor(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:bitwise_xor", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_xor(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_blur(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "dst", "anchor", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:blur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::blur(src, dst, ksize, anchor, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "dst", "anchor", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:blur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::blur(src, dst, ksize, anchor, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_borderInterpolate(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_p = NULL;
    int p=0;
    PyObject* pyobj_len = NULL;
    int len=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=0;
    int retval;

    const char* keywords[] = { "p", "len", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:borderInterpolate", (char**)keywords, &pyobj_p, &pyobj_len, &pyobj_borderType) &&
        pyopencv_to(pyobj_p, p, ArgInfo("p", 0)) &&
        pyopencv_to(pyobj_len, len, ArgInfo("len", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(retval = cv::borderInterpolate(p, len, borderType));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_boundingRect(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_array = NULL;
    Mat array;
    Rect retval;

    const char* keywords[] = { "array", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:boundingRect", (char**)keywords, &pyobj_array) &&
        pyopencv_to(pyobj_array, array, ArgInfo("array", 0)) )
    {
        ERRWRAP2(retval = cv::boundingRect(array));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_array = NULL;
    UMat array;
    Rect retval;

    const char* keywords[] = { "array", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:boundingRect", (char**)keywords, &pyobj_array) &&
        pyopencv_to(pyobj_array, array, ArgInfo("array", 0)) )
    {
        ERRWRAP2(retval = cv::boundingRect(array));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_boxFilter(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_normalize = NULL;
    bool normalize=true;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "ksize", "dst", "anchor", "normalize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:boxFilter", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_normalize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::boxFilter(src, dst, ddepth, ksize, anchor, normalize, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_normalize = NULL;
    bool normalize=true;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "ksize", "dst", "anchor", "normalize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:boxFilter", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_normalize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::boxFilter(src, dst, ddepth, ksize, anchor, normalize, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_boxPoints(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_box = NULL;
    RotatedRect box;
    PyObject* pyobj_points = NULL;
    Mat points;

    const char* keywords[] = { "box", "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:boxPoints", (char**)keywords, &pyobj_box, &pyobj_points) &&
        pyopencv_to(pyobj_box, box, ArgInfo("box", 0)) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 1)) )
    {
        ERRWRAP2(cv::boxPoints(box, points));
        return pyopencv_from(points);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_box = NULL;
    RotatedRect box;
    PyObject* pyobj_points = NULL;
    UMat points;

    const char* keywords[] = { "box", "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:boxPoints", (char**)keywords, &pyobj_box, &pyobj_points) &&
        pyopencv_to(pyobj_box, box, ArgInfo("box", 0)) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 1)) )
    {
        ERRWRAP2(cv::boxPoints(box, points));
        return pyopencv_from(points);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_buildOpticalFlowPyramid(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pyramid = NULL;
    vector_Mat pyramid;
    PyObject* pyobj_winSize = NULL;
    Size winSize;
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=0;
    PyObject* pyobj_withDerivatives = NULL;
    bool withDerivatives=true;
    PyObject* pyobj_pyrBorder = NULL;
    int pyrBorder=BORDER_REFLECT_101;
    PyObject* pyobj_derivBorder = NULL;
    int derivBorder=BORDER_CONSTANT;
    PyObject* pyobj_tryReuseInputImage = NULL;
    bool tryReuseInputImage=true;
    int retval;

    const char* keywords[] = { "img", "winSize", "maxLevel", "pyramid", "withDerivatives", "pyrBorder", "derivBorder", "tryReuseInputImage", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOOO:buildOpticalFlowPyramid", (char**)keywords, &pyobj_img, &pyobj_winSize, &pyobj_maxLevel, &pyobj_pyramid, &pyobj_withDerivatives, &pyobj_pyrBorder, &pyobj_derivBorder, &pyobj_tryReuseInputImage) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_pyramid, pyramid, ArgInfo("pyramid", 1)) &&
        pyopencv_to(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to(pyobj_withDerivatives, withDerivatives, ArgInfo("withDerivatives", 0)) &&
        pyopencv_to(pyobj_pyrBorder, pyrBorder, ArgInfo("pyrBorder", 0)) &&
        pyopencv_to(pyobj_derivBorder, derivBorder, ArgInfo("derivBorder", 0)) &&
        pyopencv_to(pyobj_tryReuseInputImage, tryReuseInputImage, ArgInfo("tryReuseInputImage", 0)) )
    {
        ERRWRAP2(retval = cv::buildOpticalFlowPyramid(img, pyramid, winSize, maxLevel, withDerivatives, pyrBorder, derivBorder, tryReuseInputImage));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(pyramid));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pyramid = NULL;
    vector_UMat pyramid;
    PyObject* pyobj_winSize = NULL;
    Size winSize;
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=0;
    PyObject* pyobj_withDerivatives = NULL;
    bool withDerivatives=true;
    PyObject* pyobj_pyrBorder = NULL;
    int pyrBorder=BORDER_REFLECT_101;
    PyObject* pyobj_derivBorder = NULL;
    int derivBorder=BORDER_CONSTANT;
    PyObject* pyobj_tryReuseInputImage = NULL;
    bool tryReuseInputImage=true;
    int retval;

    const char* keywords[] = { "img", "winSize", "maxLevel", "pyramid", "withDerivatives", "pyrBorder", "derivBorder", "tryReuseInputImage", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOOO:buildOpticalFlowPyramid", (char**)keywords, &pyobj_img, &pyobj_winSize, &pyobj_maxLevel, &pyobj_pyramid, &pyobj_withDerivatives, &pyobj_pyrBorder, &pyobj_derivBorder, &pyobj_tryReuseInputImage) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_pyramid, pyramid, ArgInfo("pyramid", 1)) &&
        pyopencv_to(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to(pyobj_withDerivatives, withDerivatives, ArgInfo("withDerivatives", 0)) &&
        pyopencv_to(pyobj_pyrBorder, pyrBorder, ArgInfo("pyrBorder", 0)) &&
        pyopencv_to(pyobj_derivBorder, derivBorder, ArgInfo("derivBorder", 0)) &&
        pyopencv_to(pyobj_tryReuseInputImage, tryReuseInputImage, ArgInfo("tryReuseInputImage", 0)) )
    {
        ERRWRAP2(retval = cv::buildOpticalFlowPyramid(img, pyramid, winSize, maxLevel, withDerivatives, pyrBorder, derivBorder, tryReuseInputImage));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(pyramid));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calcBackProject(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_images = NULL;
    vector_Mat images;
    PyObject* pyobj_channels = NULL;
    vector_int channels;
    PyObject* pyobj_hist = NULL;
    Mat hist;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ranges = NULL;
    vector_float ranges;
    PyObject* pyobj_scale = NULL;
    double scale=0;

    const char* keywords[] = { "images", "channels", "hist", "ranges", "scale", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|O:calcBackProject", (char**)keywords, &pyobj_images, &pyobj_channels, &pyobj_hist, &pyobj_ranges, &pyobj_scale, &pyobj_dst) &&
        pyopencv_to(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to(pyobj_channels, channels, ArgInfo("channels", 0)) &&
        pyopencv_to(pyobj_hist, hist, ArgInfo("hist", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ranges, ranges, ArgInfo("ranges", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) )
    {
        ERRWRAP2(cv::calcBackProject(images, channels, hist, dst, ranges, scale));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_images = NULL;
    vector_UMat images;
    PyObject* pyobj_channels = NULL;
    vector_int channels;
    PyObject* pyobj_hist = NULL;
    UMat hist;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ranges = NULL;
    vector_float ranges;
    PyObject* pyobj_scale = NULL;
    double scale=0;

    const char* keywords[] = { "images", "channels", "hist", "ranges", "scale", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|O:calcBackProject", (char**)keywords, &pyobj_images, &pyobj_channels, &pyobj_hist, &pyobj_ranges, &pyobj_scale, &pyobj_dst) &&
        pyopencv_to(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to(pyobj_channels, channels, ArgInfo("channels", 0)) &&
        pyopencv_to(pyobj_hist, hist, ArgInfo("hist", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ranges, ranges, ArgInfo("ranges", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) )
    {
        ERRWRAP2(cv::calcBackProject(images, channels, hist, dst, ranges, scale));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calcCovarMatrix(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_samples = NULL;
    Mat samples;
    PyObject* pyobj_covar = NULL;
    Mat covar;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_ctype = NULL;
    int ctype=CV_64F;

    const char* keywords[] = { "samples", "mean", "flags", "covar", "ctype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:calcCovarMatrix", (char**)keywords, &pyobj_samples, &pyobj_mean, &pyobj_flags, &pyobj_covar, &pyobj_ctype) &&
        pyopencv_to(pyobj_samples, samples, ArgInfo("samples", 0)) &&
        pyopencv_to(pyobj_covar, covar, ArgInfo("covar", 1)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_ctype, ctype, ArgInfo("ctype", 0)) )
    {
        ERRWRAP2(cv::calcCovarMatrix(samples, covar, mean, flags, ctype));
        return Py_BuildValue("(NN)", pyopencv_from(covar), pyopencv_from(mean));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_samples = NULL;
    UMat samples;
    PyObject* pyobj_covar = NULL;
    UMat covar;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_ctype = NULL;
    int ctype=CV_64F;

    const char* keywords[] = { "samples", "mean", "flags", "covar", "ctype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:calcCovarMatrix", (char**)keywords, &pyobj_samples, &pyobj_mean, &pyobj_flags, &pyobj_covar, &pyobj_ctype) &&
        pyopencv_to(pyobj_samples, samples, ArgInfo("samples", 0)) &&
        pyopencv_to(pyobj_covar, covar, ArgInfo("covar", 1)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_ctype, ctype, ArgInfo("ctype", 0)) )
    {
        ERRWRAP2(cv::calcCovarMatrix(samples, covar, mean, flags, ctype));
        return Py_BuildValue("(NN)", pyopencv_from(covar), pyopencv_from(mean));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calcHist(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_images = NULL;
    vector_Mat images;
    PyObject* pyobj_channels = NULL;
    vector_int channels;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_hist = NULL;
    Mat hist;
    PyObject* pyobj_histSize = NULL;
    vector_int histSize;
    PyObject* pyobj_ranges = NULL;
    vector_float ranges;
    PyObject* pyobj_accumulate = NULL;
    bool accumulate=false;

    const char* keywords[] = { "images", "channels", "mask", "histSize", "ranges", "hist", "accumulate", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OO:calcHist", (char**)keywords, &pyobj_images, &pyobj_channels, &pyobj_mask, &pyobj_histSize, &pyobj_ranges, &pyobj_hist, &pyobj_accumulate) &&
        pyopencv_to(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to(pyobj_channels, channels, ArgInfo("channels", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to(pyobj_histSize, histSize, ArgInfo("histSize", 0)) &&
        pyopencv_to(pyobj_ranges, ranges, ArgInfo("ranges", 0)) &&
        pyopencv_to(pyobj_accumulate, accumulate, ArgInfo("accumulate", 0)) )
    {
        ERRWRAP2(cv::calcHist(images, channels, mask, hist, histSize, ranges, accumulate));
        return pyopencv_from(hist);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_images = NULL;
    vector_UMat images;
    PyObject* pyobj_channels = NULL;
    vector_int channels;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_hist = NULL;
    UMat hist;
    PyObject* pyobj_histSize = NULL;
    vector_int histSize;
    PyObject* pyobj_ranges = NULL;
    vector_float ranges;
    PyObject* pyobj_accumulate = NULL;
    bool accumulate=false;

    const char* keywords[] = { "images", "channels", "mask", "histSize", "ranges", "hist", "accumulate", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OO:calcHist", (char**)keywords, &pyobj_images, &pyobj_channels, &pyobj_mask, &pyobj_histSize, &pyobj_ranges, &pyobj_hist, &pyobj_accumulate) &&
        pyopencv_to(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to(pyobj_channels, channels, ArgInfo("channels", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to(pyobj_histSize, histSize, ArgInfo("histSize", 0)) &&
        pyopencv_to(pyobj_ranges, ranges, ArgInfo("ranges", 0)) &&
        pyopencv_to(pyobj_accumulate, accumulate, ArgInfo("accumulate", 0)) )
    {
        ERRWRAP2(cv::calcHist(images, channels, mask, hist, histSize, ranges, accumulate));
        return pyopencv_from(hist);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calcOpticalFlowFarneback(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_prev = NULL;
    Mat prev;
    PyObject* pyobj_next = NULL;
    Mat next;
    PyObject* pyobj_flow = NULL;
    Mat flow;
    PyObject* pyobj_pyr_scale = NULL;
    double pyr_scale=0;
    PyObject* pyobj_levels = NULL;
    int levels=0;
    PyObject* pyobj_winsize = NULL;
    int winsize=0;
    PyObject* pyobj_iterations = NULL;
    int iterations=0;
    PyObject* pyobj_poly_n = NULL;
    int poly_n=0;
    PyObject* pyobj_poly_sigma = NULL;
    double poly_sigma=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "prev", "next", "flow", "pyr_scale", "levels", "winsize", "iterations", "poly_n", "poly_sigma", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOO:calcOpticalFlowFarneback", (char**)keywords, &pyobj_prev, &pyobj_next, &pyobj_flow, &pyobj_pyr_scale, &pyobj_levels, &pyobj_winsize, &pyobj_iterations, &pyobj_poly_n, &pyobj_poly_sigma, &pyobj_flags) &&
        pyopencv_to(pyobj_prev, prev, ArgInfo("prev", 0)) &&
        pyopencv_to(pyobj_next, next, ArgInfo("next", 0)) &&
        pyopencv_to(pyobj_flow, flow, ArgInfo("flow", 1)) &&
        pyopencv_to(pyobj_pyr_scale, pyr_scale, ArgInfo("pyr_scale", 0)) &&
        pyopencv_to(pyobj_levels, levels, ArgInfo("levels", 0)) &&
        pyopencv_to(pyobj_winsize, winsize, ArgInfo("winsize", 0)) &&
        pyopencv_to(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to(pyobj_poly_n, poly_n, ArgInfo("poly_n", 0)) &&
        pyopencv_to(pyobj_poly_sigma, poly_sigma, ArgInfo("poly_sigma", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::calcOpticalFlowFarneback(prev, next, flow, pyr_scale, levels, winsize, iterations, poly_n, poly_sigma, flags));
        return pyopencv_from(flow);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_prev = NULL;
    UMat prev;
    PyObject* pyobj_next = NULL;
    UMat next;
    PyObject* pyobj_flow = NULL;
    UMat flow;
    PyObject* pyobj_pyr_scale = NULL;
    double pyr_scale=0;
    PyObject* pyobj_levels = NULL;
    int levels=0;
    PyObject* pyobj_winsize = NULL;
    int winsize=0;
    PyObject* pyobj_iterations = NULL;
    int iterations=0;
    PyObject* pyobj_poly_n = NULL;
    int poly_n=0;
    PyObject* pyobj_poly_sigma = NULL;
    double poly_sigma=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "prev", "next", "flow", "pyr_scale", "levels", "winsize", "iterations", "poly_n", "poly_sigma", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOO:calcOpticalFlowFarneback", (char**)keywords, &pyobj_prev, &pyobj_next, &pyobj_flow, &pyobj_pyr_scale, &pyobj_levels, &pyobj_winsize, &pyobj_iterations, &pyobj_poly_n, &pyobj_poly_sigma, &pyobj_flags) &&
        pyopencv_to(pyobj_prev, prev, ArgInfo("prev", 0)) &&
        pyopencv_to(pyobj_next, next, ArgInfo("next", 0)) &&
        pyopencv_to(pyobj_flow, flow, ArgInfo("flow", 1)) &&
        pyopencv_to(pyobj_pyr_scale, pyr_scale, ArgInfo("pyr_scale", 0)) &&
        pyopencv_to(pyobj_levels, levels, ArgInfo("levels", 0)) &&
        pyopencv_to(pyobj_winsize, winsize, ArgInfo("winsize", 0)) &&
        pyopencv_to(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to(pyobj_poly_n, poly_n, ArgInfo("poly_n", 0)) &&
        pyopencv_to(pyobj_poly_sigma, poly_sigma, ArgInfo("poly_sigma", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::calcOpticalFlowFarneback(prev, next, flow, pyr_scale, levels, winsize, iterations, poly_n, poly_sigma, flags));
        return pyopencv_from(flow);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calcOpticalFlowPyrLK(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_prevImg = NULL;
    Mat prevImg;
    PyObject* pyobj_nextImg = NULL;
    Mat nextImg;
    PyObject* pyobj_prevPts = NULL;
    Mat prevPts;
    PyObject* pyobj_nextPts = NULL;
    Mat nextPts;
    PyObject* pyobj_status = NULL;
    Mat status;
    PyObject* pyobj_err = NULL;
    Mat err;
    PyObject* pyobj_winSize = NULL;
    Size winSize=Size(21,21);
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=3;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 0.01);
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_minEigThreshold = NULL;
    double minEigThreshold=1e-4;

    const char* keywords[] = { "prevImg", "nextImg", "prevPts", "nextPts", "status", "err", "winSize", "maxLevel", "criteria", "flags", "minEigThreshold", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOOOO:calcOpticalFlowPyrLK", (char**)keywords, &pyobj_prevImg, &pyobj_nextImg, &pyobj_prevPts, &pyobj_nextPts, &pyobj_status, &pyobj_err, &pyobj_winSize, &pyobj_maxLevel, &pyobj_criteria, &pyobj_flags, &pyobj_minEigThreshold) &&
        pyopencv_to(pyobj_prevImg, prevImg, ArgInfo("prevImg", 0)) &&
        pyopencv_to(pyobj_nextImg, nextImg, ArgInfo("nextImg", 0)) &&
        pyopencv_to(pyobj_prevPts, prevPts, ArgInfo("prevPts", 0)) &&
        pyopencv_to(pyobj_nextPts, nextPts, ArgInfo("nextPts", 1)) &&
        pyopencv_to(pyobj_status, status, ArgInfo("status", 1)) &&
        pyopencv_to(pyobj_err, err, ArgInfo("err", 1)) &&
        pyopencv_to(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_minEigThreshold, minEigThreshold, ArgInfo("minEigThreshold", 0)) )
    {
        ERRWRAP2(cv::calcOpticalFlowPyrLK(prevImg, nextImg, prevPts, nextPts, status, err, winSize, maxLevel, criteria, flags, minEigThreshold));
        return Py_BuildValue("(NNN)", pyopencv_from(nextPts), pyopencv_from(status), pyopencv_from(err));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_prevImg = NULL;
    UMat prevImg;
    PyObject* pyobj_nextImg = NULL;
    UMat nextImg;
    PyObject* pyobj_prevPts = NULL;
    UMat prevPts;
    PyObject* pyobj_nextPts = NULL;
    UMat nextPts;
    PyObject* pyobj_status = NULL;
    UMat status;
    PyObject* pyobj_err = NULL;
    UMat err;
    PyObject* pyobj_winSize = NULL;
    Size winSize=Size(21,21);
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=3;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 0.01);
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_minEigThreshold = NULL;
    double minEigThreshold=1e-4;

    const char* keywords[] = { "prevImg", "nextImg", "prevPts", "nextPts", "status", "err", "winSize", "maxLevel", "criteria", "flags", "minEigThreshold", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOOOO:calcOpticalFlowPyrLK", (char**)keywords, &pyobj_prevImg, &pyobj_nextImg, &pyobj_prevPts, &pyobj_nextPts, &pyobj_status, &pyobj_err, &pyobj_winSize, &pyobj_maxLevel, &pyobj_criteria, &pyobj_flags, &pyobj_minEigThreshold) &&
        pyopencv_to(pyobj_prevImg, prevImg, ArgInfo("prevImg", 0)) &&
        pyopencv_to(pyobj_nextImg, nextImg, ArgInfo("nextImg", 0)) &&
        pyopencv_to(pyobj_prevPts, prevPts, ArgInfo("prevPts", 0)) &&
        pyopencv_to(pyobj_nextPts, nextPts, ArgInfo("nextPts", 1)) &&
        pyopencv_to(pyobj_status, status, ArgInfo("status", 1)) &&
        pyopencv_to(pyobj_err, err, ArgInfo("err", 1)) &&
        pyopencv_to(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_minEigThreshold, minEigThreshold, ArgInfo("minEigThreshold", 0)) )
    {
        ERRWRAP2(cv::calcOpticalFlowPyrLK(prevImg, nextImg, prevPts, nextPts, status, err, winSize, maxLevel, criteria, flags, minEigThreshold));
        return Py_BuildValue("(NNN)", pyopencv_from(nextPts), pyopencv_from(status), pyopencv_from(err));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calibrateCamera(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_Mat imagePoints;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_Mat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_Mat tvecs;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "cameraMatrix", "distCoeffs", "rvecs", "tvecs", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOOO:calibrateCamera", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_imageSize, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvecs, &pyobj_tvecs, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 1)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 1)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, flags, criteria));
        return Py_BuildValue("(NNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix), pyopencv_from(distCoeffs), pyopencv_from(rvecs), pyopencv_from(tvecs));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_UMat imagePoints;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_UMat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_UMat tvecs;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "cameraMatrix", "distCoeffs", "rvecs", "tvecs", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOOO:calibrateCamera", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_imageSize, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvecs, &pyobj_tvecs, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 1)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 1)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, flags, criteria));
        return Py_BuildValue("(NNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix), pyopencv_from(distCoeffs), pyopencv_from(rvecs), pyopencv_from(tvecs));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calibrateCameraExtended(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_Mat imagePoints;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_Mat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_Mat tvecs;
    PyObject* pyobj_stdDeviationsIntrinsics = NULL;
    Mat stdDeviationsIntrinsics;
    PyObject* pyobj_stdDeviationsExtrinsics = NULL;
    Mat stdDeviationsExtrinsics;
    PyObject* pyobj_perViewErrors = NULL;
    Mat perViewErrors;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "cameraMatrix", "distCoeffs", "rvecs", "tvecs", "stdDeviationsIntrinsics", "stdDeviationsExtrinsics", "perViewErrors", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOOOOOO:calibrateCameraExtended", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_imageSize, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvecs, &pyobj_tvecs, &pyobj_stdDeviationsIntrinsics, &pyobj_stdDeviationsExtrinsics, &pyobj_perViewErrors, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 1)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 1)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_stdDeviationsIntrinsics, stdDeviationsIntrinsics, ArgInfo("stdDeviationsIntrinsics", 1)) &&
        pyopencv_to(pyobj_stdDeviationsExtrinsics, stdDeviationsExtrinsics, ArgInfo("stdDeviationsExtrinsics", 1)) &&
        pyopencv_to(pyobj_perViewErrors, perViewErrors, ArgInfo("perViewErrors", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors, flags, criteria));
        return Py_BuildValue("(NNNNNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix), pyopencv_from(distCoeffs), pyopencv_from(rvecs), pyopencv_from(tvecs), pyopencv_from(stdDeviationsIntrinsics), pyopencv_from(stdDeviationsExtrinsics), pyopencv_from(perViewErrors));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_UMat imagePoints;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_UMat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_UMat tvecs;
    PyObject* pyobj_stdDeviationsIntrinsics = NULL;
    UMat stdDeviationsIntrinsics;
    PyObject* pyobj_stdDeviationsExtrinsics = NULL;
    UMat stdDeviationsExtrinsics;
    PyObject* pyobj_perViewErrors = NULL;
    UMat perViewErrors;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "cameraMatrix", "distCoeffs", "rvecs", "tvecs", "stdDeviationsIntrinsics", "stdDeviationsExtrinsics", "perViewErrors", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOOOOOO:calibrateCameraExtended", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_imageSize, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvecs, &pyobj_tvecs, &pyobj_stdDeviationsIntrinsics, &pyobj_stdDeviationsExtrinsics, &pyobj_perViewErrors, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 1)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 1)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_stdDeviationsIntrinsics, stdDeviationsIntrinsics, ArgInfo("stdDeviationsIntrinsics", 1)) &&
        pyopencv_to(pyobj_stdDeviationsExtrinsics, stdDeviationsExtrinsics, ArgInfo("stdDeviationsExtrinsics", 1)) &&
        pyopencv_to(pyobj_perViewErrors, perViewErrors, ArgInfo("perViewErrors", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors, flags, criteria));
        return Py_BuildValue("(NNNNNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix), pyopencv_from(distCoeffs), pyopencv_from(rvecs), pyopencv_from(tvecs), pyopencv_from(stdDeviationsIntrinsics), pyopencv_from(stdDeviationsExtrinsics), pyopencv_from(perViewErrors));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calibrateCameraRO(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_Mat imagePoints;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_iFixedPoint = NULL;
    int iFixedPoint=0;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_Mat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_Mat tvecs;
    PyObject* pyobj_newObjPoints = NULL;
    Mat newObjPoints;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "iFixedPoint", "cameraMatrix", "distCoeffs", "rvecs", "tvecs", "newObjPoints", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OOOOO:calibrateCameraRO", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_imageSize, &pyobj_iFixedPoint, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvecs, &pyobj_tvecs, &pyobj_newObjPoints, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_iFixedPoint, iFixedPoint, ArgInfo("iFixedPoint", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 1)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 1)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_newObjPoints, newObjPoints, ArgInfo("newObjPoints", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::calibrateCameraRO(objectPoints, imagePoints, imageSize, iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, flags, criteria));
        return Py_BuildValue("(NNNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix), pyopencv_from(distCoeffs), pyopencv_from(rvecs), pyopencv_from(tvecs), pyopencv_from(newObjPoints));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_UMat imagePoints;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_iFixedPoint = NULL;
    int iFixedPoint=0;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_UMat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_UMat tvecs;
    PyObject* pyobj_newObjPoints = NULL;
    UMat newObjPoints;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "iFixedPoint", "cameraMatrix", "distCoeffs", "rvecs", "tvecs", "newObjPoints", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OOOOO:calibrateCameraRO", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_imageSize, &pyobj_iFixedPoint, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvecs, &pyobj_tvecs, &pyobj_newObjPoints, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_iFixedPoint, iFixedPoint, ArgInfo("iFixedPoint", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 1)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 1)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_newObjPoints, newObjPoints, ArgInfo("newObjPoints", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::calibrateCameraRO(objectPoints, imagePoints, imageSize, iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, flags, criteria));
        return Py_BuildValue("(NNNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix), pyopencv_from(distCoeffs), pyopencv_from(rvecs), pyopencv_from(tvecs), pyopencv_from(newObjPoints));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calibrateCameraROExtended(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_Mat imagePoints;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_iFixedPoint = NULL;
    int iFixedPoint=0;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_Mat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_Mat tvecs;
    PyObject* pyobj_newObjPoints = NULL;
    Mat newObjPoints;
    PyObject* pyobj_stdDeviationsIntrinsics = NULL;
    Mat stdDeviationsIntrinsics;
    PyObject* pyobj_stdDeviationsExtrinsics = NULL;
    Mat stdDeviationsExtrinsics;
    PyObject* pyobj_stdDeviationsObjPoints = NULL;
    Mat stdDeviationsObjPoints;
    PyObject* pyobj_perViewErrors = NULL;
    Mat perViewErrors;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "iFixedPoint", "cameraMatrix", "distCoeffs", "rvecs", "tvecs", "newObjPoints", "stdDeviationsIntrinsics", "stdDeviationsExtrinsics", "stdDeviationsObjPoints", "perViewErrors", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OOOOOOOOO:calibrateCameraROExtended", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_imageSize, &pyobj_iFixedPoint, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvecs, &pyobj_tvecs, &pyobj_newObjPoints, &pyobj_stdDeviationsIntrinsics, &pyobj_stdDeviationsExtrinsics, &pyobj_stdDeviationsObjPoints, &pyobj_perViewErrors, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_iFixedPoint, iFixedPoint, ArgInfo("iFixedPoint", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 1)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 1)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_newObjPoints, newObjPoints, ArgInfo("newObjPoints", 1)) &&
        pyopencv_to(pyobj_stdDeviationsIntrinsics, stdDeviationsIntrinsics, ArgInfo("stdDeviationsIntrinsics", 1)) &&
        pyopencv_to(pyobj_stdDeviationsExtrinsics, stdDeviationsExtrinsics, ArgInfo("stdDeviationsExtrinsics", 1)) &&
        pyopencv_to(pyobj_stdDeviationsObjPoints, stdDeviationsObjPoints, ArgInfo("stdDeviationsObjPoints", 1)) &&
        pyopencv_to(pyobj_perViewErrors, perViewErrors, ArgInfo("perViewErrors", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::calibrateCameraRO(objectPoints, imagePoints, imageSize, iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, stdDeviationsIntrinsics, stdDeviationsExtrinsics, stdDeviationsObjPoints, perViewErrors, flags, criteria));
        return Py_BuildValue("(NNNNNNNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix), pyopencv_from(distCoeffs), pyopencv_from(rvecs), pyopencv_from(tvecs), pyopencv_from(newObjPoints), pyopencv_from(stdDeviationsIntrinsics), pyopencv_from(stdDeviationsExtrinsics), pyopencv_from(stdDeviationsObjPoints), pyopencv_from(perViewErrors));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_UMat imagePoints;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_iFixedPoint = NULL;
    int iFixedPoint=0;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_UMat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_UMat tvecs;
    PyObject* pyobj_newObjPoints = NULL;
    UMat newObjPoints;
    PyObject* pyobj_stdDeviationsIntrinsics = NULL;
    UMat stdDeviationsIntrinsics;
    PyObject* pyobj_stdDeviationsExtrinsics = NULL;
    UMat stdDeviationsExtrinsics;
    PyObject* pyobj_stdDeviationsObjPoints = NULL;
    UMat stdDeviationsObjPoints;
    PyObject* pyobj_perViewErrors = NULL;
    UMat perViewErrors;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "iFixedPoint", "cameraMatrix", "distCoeffs", "rvecs", "tvecs", "newObjPoints", "stdDeviationsIntrinsics", "stdDeviationsExtrinsics", "stdDeviationsObjPoints", "perViewErrors", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OOOOOOOOO:calibrateCameraROExtended", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_imageSize, &pyobj_iFixedPoint, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvecs, &pyobj_tvecs, &pyobj_newObjPoints, &pyobj_stdDeviationsIntrinsics, &pyobj_stdDeviationsExtrinsics, &pyobj_stdDeviationsObjPoints, &pyobj_perViewErrors, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_iFixedPoint, iFixedPoint, ArgInfo("iFixedPoint", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 1)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 1)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_newObjPoints, newObjPoints, ArgInfo("newObjPoints", 1)) &&
        pyopencv_to(pyobj_stdDeviationsIntrinsics, stdDeviationsIntrinsics, ArgInfo("stdDeviationsIntrinsics", 1)) &&
        pyopencv_to(pyobj_stdDeviationsExtrinsics, stdDeviationsExtrinsics, ArgInfo("stdDeviationsExtrinsics", 1)) &&
        pyopencv_to(pyobj_stdDeviationsObjPoints, stdDeviationsObjPoints, ArgInfo("stdDeviationsObjPoints", 1)) &&
        pyopencv_to(pyobj_perViewErrors, perViewErrors, ArgInfo("perViewErrors", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::calibrateCameraRO(objectPoints, imagePoints, imageSize, iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, stdDeviationsIntrinsics, stdDeviationsExtrinsics, stdDeviationsObjPoints, perViewErrors, flags, criteria));
        return Py_BuildValue("(NNNNNNNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix), pyopencv_from(distCoeffs), pyopencv_from(rvecs), pyopencv_from(tvecs), pyopencv_from(newObjPoints), pyopencv_from(stdDeviationsIntrinsics), pyopencv_from(stdDeviationsExtrinsics), pyopencv_from(stdDeviationsObjPoints), pyopencv_from(perViewErrors));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calibrateHandEye(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_R_gripper2base = NULL;
    vector_Mat R_gripper2base;
    PyObject* pyobj_t_gripper2base = NULL;
    vector_Mat t_gripper2base;
    PyObject* pyobj_R_target2cam = NULL;
    vector_Mat R_target2cam;
    PyObject* pyobj_t_target2cam = NULL;
    vector_Mat t_target2cam;
    PyObject* pyobj_R_cam2gripper = NULL;
    Mat R_cam2gripper;
    PyObject* pyobj_t_cam2gripper = NULL;
    Mat t_cam2gripper;
    PyObject* pyobj_method = NULL;
    HandEyeCalibrationMethod method=CALIB_HAND_EYE_TSAI;

    const char* keywords[] = { "R_gripper2base", "t_gripper2base", "R_target2cam", "t_target2cam", "R_cam2gripper", "t_cam2gripper", "method", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:calibrateHandEye", (char**)keywords, &pyobj_R_gripper2base, &pyobj_t_gripper2base, &pyobj_R_target2cam, &pyobj_t_target2cam, &pyobj_R_cam2gripper, &pyobj_t_cam2gripper, &pyobj_method) &&
        pyopencv_to(pyobj_R_gripper2base, R_gripper2base, ArgInfo("R_gripper2base", 0)) &&
        pyopencv_to(pyobj_t_gripper2base, t_gripper2base, ArgInfo("t_gripper2base", 0)) &&
        pyopencv_to(pyobj_R_target2cam, R_target2cam, ArgInfo("R_target2cam", 0)) &&
        pyopencv_to(pyobj_t_target2cam, t_target2cam, ArgInfo("t_target2cam", 0)) &&
        pyopencv_to(pyobj_R_cam2gripper, R_cam2gripper, ArgInfo("R_cam2gripper", 1)) &&
        pyopencv_to(pyobj_t_cam2gripper, t_cam2gripper, ArgInfo("t_cam2gripper", 1)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) )
    {
        ERRWRAP2(cv::calibrateHandEye(R_gripper2base, t_gripper2base, R_target2cam, t_target2cam, R_cam2gripper, t_cam2gripper, method));
        return Py_BuildValue("(NN)", pyopencv_from(R_cam2gripper), pyopencv_from(t_cam2gripper));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_R_gripper2base = NULL;
    vector_UMat R_gripper2base;
    PyObject* pyobj_t_gripper2base = NULL;
    vector_UMat t_gripper2base;
    PyObject* pyobj_R_target2cam = NULL;
    vector_UMat R_target2cam;
    PyObject* pyobj_t_target2cam = NULL;
    vector_UMat t_target2cam;
    PyObject* pyobj_R_cam2gripper = NULL;
    UMat R_cam2gripper;
    PyObject* pyobj_t_cam2gripper = NULL;
    UMat t_cam2gripper;
    PyObject* pyobj_method = NULL;
    HandEyeCalibrationMethod method=CALIB_HAND_EYE_TSAI;

    const char* keywords[] = { "R_gripper2base", "t_gripper2base", "R_target2cam", "t_target2cam", "R_cam2gripper", "t_cam2gripper", "method", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:calibrateHandEye", (char**)keywords, &pyobj_R_gripper2base, &pyobj_t_gripper2base, &pyobj_R_target2cam, &pyobj_t_target2cam, &pyobj_R_cam2gripper, &pyobj_t_cam2gripper, &pyobj_method) &&
        pyopencv_to(pyobj_R_gripper2base, R_gripper2base, ArgInfo("R_gripper2base", 0)) &&
        pyopencv_to(pyobj_t_gripper2base, t_gripper2base, ArgInfo("t_gripper2base", 0)) &&
        pyopencv_to(pyobj_R_target2cam, R_target2cam, ArgInfo("R_target2cam", 0)) &&
        pyopencv_to(pyobj_t_target2cam, t_target2cam, ArgInfo("t_target2cam", 0)) &&
        pyopencv_to(pyobj_R_cam2gripper, R_cam2gripper, ArgInfo("R_cam2gripper", 1)) &&
        pyopencv_to(pyobj_t_cam2gripper, t_cam2gripper, ArgInfo("t_cam2gripper", 1)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) )
    {
        ERRWRAP2(cv::calibrateHandEye(R_gripper2base, t_gripper2base, R_target2cam, t_target2cam, R_cam2gripper, t_cam2gripper, method));
        return Py_BuildValue("(NN)", pyopencv_from(R_cam2gripper), pyopencv_from(t_cam2gripper));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_calibrationMatrixValues(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_apertureWidth = NULL;
    double apertureWidth=0;
    PyObject* pyobj_apertureHeight = NULL;
    double apertureHeight=0;
    double fovx;
    double fovy;
    double focalLength;
    Point2d principalPoint;
    double aspectRatio;

    const char* keywords[] = { "cameraMatrix", "imageSize", "apertureWidth", "apertureHeight", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO:calibrationMatrixValues", (char**)keywords, &pyobj_cameraMatrix, &pyobj_imageSize, &pyobj_apertureWidth, &pyobj_apertureHeight) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_apertureWidth, apertureWidth, ArgInfo("apertureWidth", 0)) &&
        pyopencv_to(pyobj_apertureHeight, apertureHeight, ArgInfo("apertureHeight", 0)) )
    {
        ERRWRAP2(cv::calibrationMatrixValues(cameraMatrix, imageSize, apertureWidth, apertureHeight, fovx, fovy, focalLength, principalPoint, aspectRatio));
        return Py_BuildValue("(NNNNN)", pyopencv_from(fovx), pyopencv_from(fovy), pyopencv_from(focalLength), pyopencv_from(principalPoint), pyopencv_from(aspectRatio));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_apertureWidth = NULL;
    double apertureWidth=0;
    PyObject* pyobj_apertureHeight = NULL;
    double apertureHeight=0;
    double fovx;
    double fovy;
    double focalLength;
    Point2d principalPoint;
    double aspectRatio;

    const char* keywords[] = { "cameraMatrix", "imageSize", "apertureWidth", "apertureHeight", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO:calibrationMatrixValues", (char**)keywords, &pyobj_cameraMatrix, &pyobj_imageSize, &pyobj_apertureWidth, &pyobj_apertureHeight) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_apertureWidth, apertureWidth, ArgInfo("apertureWidth", 0)) &&
        pyopencv_to(pyobj_apertureHeight, apertureHeight, ArgInfo("apertureHeight", 0)) )
    {
        ERRWRAP2(cv::calibrationMatrixValues(cameraMatrix, imageSize, apertureWidth, apertureHeight, fovx, fovy, focalLength, principalPoint, aspectRatio));
        return Py_BuildValue("(NNNNN)", pyopencv_from(fovx), pyopencv_from(fovy), pyopencv_from(focalLength), pyopencv_from(principalPoint), pyopencv_from(aspectRatio));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_cartToPolar(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;
    PyObject* pyobj_angle = NULL;
    Mat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "x", "y", "magnitude", "angle", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:cartToPolar", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_angle, &pyobj_angleInDegrees) &&
        pyopencv_to(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::cartToPolar(x, y, magnitude, angle, angleInDegrees));
        return Py_BuildValue("(NN)", pyopencv_from(magnitude), pyopencv_from(angle));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;
    PyObject* pyobj_angle = NULL;
    UMat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "x", "y", "magnitude", "angle", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:cartToPolar", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_angle, &pyobj_angleInDegrees) &&
        pyopencv_to(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::cartToPolar(x, y, magnitude, angle, angleInDegrees));
        return Py_BuildValue("(NN)", pyopencv_from(magnitude), pyopencv_from(angle));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_checkChessboard(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_size = NULL;
    Size size;
    bool retval;

    const char* keywords[] = { "img", "size", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:checkChessboard", (char**)keywords, &pyobj_img, &pyobj_size) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) )
    {
        ERRWRAP2(retval = cv::checkChessboard(img, size));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_size = NULL;
    Size size;
    bool retval;

    const char* keywords[] = { "img", "size", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:checkChessboard", (char**)keywords, &pyobj_img, &pyobj_size) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) )
    {
        ERRWRAP2(retval = cv::checkChessboard(img, size));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_checkHardwareSupport(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_feature = NULL;
    int feature=0;
    bool retval;

    const char* keywords[] = { "feature", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:checkHardwareSupport", (char**)keywords, &pyobj_feature) &&
        pyopencv_to(pyobj_feature, feature, ArgInfo("feature", 0)) )
    {
        ERRWRAP2(retval = cv::checkHardwareSupport(feature));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_checkRange(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_a = NULL;
    Mat a;
    PyObject* pyobj_quiet = NULL;
    bool quiet=true;
    Point pos;
    PyObject* pyobj_minVal = NULL;
    double minVal=-DBL_MAX;
    PyObject* pyobj_maxVal = NULL;
    double maxVal=DBL_MAX;
    bool retval;

    const char* keywords[] = { "a", "quiet", "minVal", "maxVal", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:checkRange", (char**)keywords, &pyobj_a, &pyobj_quiet, &pyobj_minVal, &pyobj_maxVal) &&
        pyopencv_to(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to(pyobj_quiet, quiet, ArgInfo("quiet", 0)) &&
        pyopencv_to(pyobj_minVal, minVal, ArgInfo("minVal", 0)) &&
        pyopencv_to(pyobj_maxVal, maxVal, ArgInfo("maxVal", 0)) )
    {
        ERRWRAP2(retval = cv::checkRange(a, quiet, &pos, minVal, maxVal));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(pos));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_a = NULL;
    UMat a;
    PyObject* pyobj_quiet = NULL;
    bool quiet=true;
    Point pos;
    PyObject* pyobj_minVal = NULL;
    double minVal=-DBL_MAX;
    PyObject* pyobj_maxVal = NULL;
    double maxVal=DBL_MAX;
    bool retval;

    const char* keywords[] = { "a", "quiet", "minVal", "maxVal", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:checkRange", (char**)keywords, &pyobj_a, &pyobj_quiet, &pyobj_minVal, &pyobj_maxVal) &&
        pyopencv_to(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to(pyobj_quiet, quiet, ArgInfo("quiet", 0)) &&
        pyopencv_to(pyobj_minVal, minVal, ArgInfo("minVal", 0)) &&
        pyopencv_to(pyobj_maxVal, maxVal, ArgInfo("maxVal", 0)) )
    {
        ERRWRAP2(retval = cv::checkRange(a, quiet, &pos, minVal, maxVal));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(pos));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_circle(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_center = NULL;
    Point center;
    PyObject* pyobj_radius = NULL;
    int radius=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "center", "radius", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:circle", (char**)keywords, &pyobj_img, &pyobj_center, &pyobj_radius, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_radius, radius, ArgInfo("radius", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::circle(img, center, radius, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_center = NULL;
    Point center;
    PyObject* pyobj_radius = NULL;
    int radius=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "center", "radius", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:circle", (char**)keywords, &pyobj_img, &pyobj_center, &pyobj_radius, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_radius, radius, ArgInfo("radius", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::circle(img, center, radius, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_clipLine(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_imgRect = NULL;
    Rect imgRect;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    bool retval;

    const char* keywords[] = { "imgRect", "pt1", "pt2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:clipLine", (char**)keywords, &pyobj_imgRect, &pyobj_pt1, &pyobj_pt2) &&
        pyopencv_to(pyobj_imgRect, imgRect, ArgInfo("imgRect", 0)) &&
        pyopencv_to(pyobj_pt1, pt1, ArgInfo("pt1", 1)) &&
        pyopencv_to(pyobj_pt2, pt2, ArgInfo("pt2", 1)) )
    {
        ERRWRAP2(retval = cv::clipLine(imgRect, pt1, pt2));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(pt1), pyopencv_from(pt2));
    }

    return NULL;
}

static PyObject* pyopencv_cv_colorChange(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_red_mul = NULL;
    float red_mul=1.0f;
    PyObject* pyobj_green_mul = NULL;
    float green_mul=1.0f;
    PyObject* pyobj_blue_mul = NULL;
    float blue_mul=1.0f;

    const char* keywords[] = { "src", "mask", "dst", "red_mul", "green_mul", "blue_mul", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:colorChange", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst, &pyobj_red_mul, &pyobj_green_mul, &pyobj_blue_mul) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_red_mul, red_mul, ArgInfo("red_mul", 0)) &&
        pyopencv_to(pyobj_green_mul, green_mul, ArgInfo("green_mul", 0)) &&
        pyopencv_to(pyobj_blue_mul, blue_mul, ArgInfo("blue_mul", 0)) )
    {
        ERRWRAP2(cv::colorChange(src, mask, dst, red_mul, green_mul, blue_mul));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_red_mul = NULL;
    float red_mul=1.0f;
    PyObject* pyobj_green_mul = NULL;
    float green_mul=1.0f;
    PyObject* pyobj_blue_mul = NULL;
    float blue_mul=1.0f;

    const char* keywords[] = { "src", "mask", "dst", "red_mul", "green_mul", "blue_mul", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:colorChange", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst, &pyobj_red_mul, &pyobj_green_mul, &pyobj_blue_mul) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_red_mul, red_mul, ArgInfo("red_mul", 0)) &&
        pyopencv_to(pyobj_green_mul, green_mul, ArgInfo("green_mul", 0)) &&
        pyopencv_to(pyobj_blue_mul, blue_mul, ArgInfo("blue_mul", 0)) )
    {
        ERRWRAP2(cv::colorChange(src, mask, dst, red_mul, green_mul, blue_mul));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_compare(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_cmpop = NULL;
    int cmpop=0;

    const char* keywords[] = { "src1", "src2", "cmpop", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:compare", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_cmpop, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_cmpop, cmpop, ArgInfo("cmpop", 0)) )
    {
        ERRWRAP2(cv::compare(src1, src2, dst, cmpop));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_cmpop = NULL;
    int cmpop=0;

    const char* keywords[] = { "src1", "src2", "cmpop", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:compare", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_cmpop, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_cmpop, cmpop, ArgInfo("cmpop", 0)) )
    {
        ERRWRAP2(cv::compare(src1, src2, dst, cmpop));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_compareHist(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_H1 = NULL;
    Mat H1;
    PyObject* pyobj_H2 = NULL;
    Mat H2;
    PyObject* pyobj_method = NULL;
    int method=0;
    double retval;

    const char* keywords[] = { "H1", "H2", "method", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:compareHist", (char**)keywords, &pyobj_H1, &pyobj_H2, &pyobj_method) &&
        pyopencv_to(pyobj_H1, H1, ArgInfo("H1", 0)) &&
        pyopencv_to(pyobj_H2, H2, ArgInfo("H2", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) )
    {
        ERRWRAP2(retval = cv::compareHist(H1, H2, method));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_H1 = NULL;
    UMat H1;
    PyObject* pyobj_H2 = NULL;
    UMat H2;
    PyObject* pyobj_method = NULL;
    int method=0;
    double retval;

    const char* keywords[] = { "H1", "H2", "method", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:compareHist", (char**)keywords, &pyobj_H1, &pyobj_H2, &pyobj_method) &&
        pyopencv_to(pyobj_H1, H1, ArgInfo("H1", 0)) &&
        pyopencv_to(pyobj_H2, H2, ArgInfo("H2", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) )
    {
        ERRWRAP2(retval = cv::compareHist(H1, H2, method));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_completeSymm(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_m = NULL;
    Mat m;
    PyObject* pyobj_lowerToUpper = NULL;
    bool lowerToUpper=false;

    const char* keywords[] = { "m", "lowerToUpper", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:completeSymm", (char**)keywords, &pyobj_m, &pyobj_lowerToUpper) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 1)) &&
        pyopencv_to(pyobj_lowerToUpper, lowerToUpper, ArgInfo("lowerToUpper", 0)) )
    {
        ERRWRAP2(cv::completeSymm(m, lowerToUpper));
        return pyopencv_from(m);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_m = NULL;
    UMat m;
    PyObject* pyobj_lowerToUpper = NULL;
    bool lowerToUpper=false;

    const char* keywords[] = { "m", "lowerToUpper", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:completeSymm", (char**)keywords, &pyobj_m, &pyobj_lowerToUpper) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 1)) &&
        pyopencv_to(pyobj_lowerToUpper, lowerToUpper, ArgInfo("lowerToUpper", 0)) )
    {
        ERRWRAP2(cv::completeSymm(m, lowerToUpper));
        return pyopencv_from(m);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_composeRT(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_rvec1 = NULL;
    Mat rvec1;
    PyObject* pyobj_tvec1 = NULL;
    Mat tvec1;
    PyObject* pyobj_rvec2 = NULL;
    Mat rvec2;
    PyObject* pyobj_tvec2 = NULL;
    Mat tvec2;
    PyObject* pyobj_rvec3 = NULL;
    Mat rvec3;
    PyObject* pyobj_tvec3 = NULL;
    Mat tvec3;
    PyObject* pyobj_dr3dr1 = NULL;
    Mat dr3dr1;
    PyObject* pyobj_dr3dt1 = NULL;
    Mat dr3dt1;
    PyObject* pyobj_dr3dr2 = NULL;
    Mat dr3dr2;
    PyObject* pyobj_dr3dt2 = NULL;
    Mat dr3dt2;
    PyObject* pyobj_dt3dr1 = NULL;
    Mat dt3dr1;
    PyObject* pyobj_dt3dt1 = NULL;
    Mat dt3dt1;
    PyObject* pyobj_dt3dr2 = NULL;
    Mat dt3dr2;
    PyObject* pyobj_dt3dt2 = NULL;
    Mat dt3dt2;

    const char* keywords[] = { "rvec1", "tvec1", "rvec2", "tvec2", "rvec3", "tvec3", "dr3dr1", "dr3dt1", "dr3dr2", "dr3dt2", "dt3dr1", "dt3dt1", "dt3dr2", "dt3dt2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOOOOOOO:composeRT", (char**)keywords, &pyobj_rvec1, &pyobj_tvec1, &pyobj_rvec2, &pyobj_tvec2, &pyobj_rvec3, &pyobj_tvec3, &pyobj_dr3dr1, &pyobj_dr3dt1, &pyobj_dr3dr2, &pyobj_dr3dt2, &pyobj_dt3dr1, &pyobj_dt3dt1, &pyobj_dt3dr2, &pyobj_dt3dt2) &&
        pyopencv_to(pyobj_rvec1, rvec1, ArgInfo("rvec1", 0)) &&
        pyopencv_to(pyobj_tvec1, tvec1, ArgInfo("tvec1", 0)) &&
        pyopencv_to(pyobj_rvec2, rvec2, ArgInfo("rvec2", 0)) &&
        pyopencv_to(pyobj_tvec2, tvec2, ArgInfo("tvec2", 0)) &&
        pyopencv_to(pyobj_rvec3, rvec3, ArgInfo("rvec3", 1)) &&
        pyopencv_to(pyobj_tvec3, tvec3, ArgInfo("tvec3", 1)) &&
        pyopencv_to(pyobj_dr3dr1, dr3dr1, ArgInfo("dr3dr1", 1)) &&
        pyopencv_to(pyobj_dr3dt1, dr3dt1, ArgInfo("dr3dt1", 1)) &&
        pyopencv_to(pyobj_dr3dr2, dr3dr2, ArgInfo("dr3dr2", 1)) &&
        pyopencv_to(pyobj_dr3dt2, dr3dt2, ArgInfo("dr3dt2", 1)) &&
        pyopencv_to(pyobj_dt3dr1, dt3dr1, ArgInfo("dt3dr1", 1)) &&
        pyopencv_to(pyobj_dt3dt1, dt3dt1, ArgInfo("dt3dt1", 1)) &&
        pyopencv_to(pyobj_dt3dr2, dt3dr2, ArgInfo("dt3dr2", 1)) &&
        pyopencv_to(pyobj_dt3dt2, dt3dt2, ArgInfo("dt3dt2", 1)) )
    {
        ERRWRAP2(cv::composeRT(rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1, dr3dt1, dr3dr2, dr3dt2, dt3dr1, dt3dt1, dt3dr2, dt3dt2));
        return Py_BuildValue("(NNNNNNNNNN)", pyopencv_from(rvec3), pyopencv_from(tvec3), pyopencv_from(dr3dr1), pyopencv_from(dr3dt1), pyopencv_from(dr3dr2), pyopencv_from(dr3dt2), pyopencv_from(dt3dr1), pyopencv_from(dt3dt1), pyopencv_from(dt3dr2), pyopencv_from(dt3dt2));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_rvec1 = NULL;
    UMat rvec1;
    PyObject* pyobj_tvec1 = NULL;
    UMat tvec1;
    PyObject* pyobj_rvec2 = NULL;
    UMat rvec2;
    PyObject* pyobj_tvec2 = NULL;
    UMat tvec2;
    PyObject* pyobj_rvec3 = NULL;
    UMat rvec3;
    PyObject* pyobj_tvec3 = NULL;
    UMat tvec3;
    PyObject* pyobj_dr3dr1 = NULL;
    UMat dr3dr1;
    PyObject* pyobj_dr3dt1 = NULL;
    UMat dr3dt1;
    PyObject* pyobj_dr3dr2 = NULL;
    UMat dr3dr2;
    PyObject* pyobj_dr3dt2 = NULL;
    UMat dr3dt2;
    PyObject* pyobj_dt3dr1 = NULL;
    UMat dt3dr1;
    PyObject* pyobj_dt3dt1 = NULL;
    UMat dt3dt1;
    PyObject* pyobj_dt3dr2 = NULL;
    UMat dt3dr2;
    PyObject* pyobj_dt3dt2 = NULL;
    UMat dt3dt2;

    const char* keywords[] = { "rvec1", "tvec1", "rvec2", "tvec2", "rvec3", "tvec3", "dr3dr1", "dr3dt1", "dr3dr2", "dr3dt2", "dt3dr1", "dt3dt1", "dt3dr2", "dt3dt2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOOOOOOO:composeRT", (char**)keywords, &pyobj_rvec1, &pyobj_tvec1, &pyobj_rvec2, &pyobj_tvec2, &pyobj_rvec3, &pyobj_tvec3, &pyobj_dr3dr1, &pyobj_dr3dt1, &pyobj_dr3dr2, &pyobj_dr3dt2, &pyobj_dt3dr1, &pyobj_dt3dt1, &pyobj_dt3dr2, &pyobj_dt3dt2) &&
        pyopencv_to(pyobj_rvec1, rvec1, ArgInfo("rvec1", 0)) &&
        pyopencv_to(pyobj_tvec1, tvec1, ArgInfo("tvec1", 0)) &&
        pyopencv_to(pyobj_rvec2, rvec2, ArgInfo("rvec2", 0)) &&
        pyopencv_to(pyobj_tvec2, tvec2, ArgInfo("tvec2", 0)) &&
        pyopencv_to(pyobj_rvec3, rvec3, ArgInfo("rvec3", 1)) &&
        pyopencv_to(pyobj_tvec3, tvec3, ArgInfo("tvec3", 1)) &&
        pyopencv_to(pyobj_dr3dr1, dr3dr1, ArgInfo("dr3dr1", 1)) &&
        pyopencv_to(pyobj_dr3dt1, dr3dt1, ArgInfo("dr3dt1", 1)) &&
        pyopencv_to(pyobj_dr3dr2, dr3dr2, ArgInfo("dr3dr2", 1)) &&
        pyopencv_to(pyobj_dr3dt2, dr3dt2, ArgInfo("dr3dt2", 1)) &&
        pyopencv_to(pyobj_dt3dr1, dt3dr1, ArgInfo("dt3dr1", 1)) &&
        pyopencv_to(pyobj_dt3dt1, dt3dt1, ArgInfo("dt3dt1", 1)) &&
        pyopencv_to(pyobj_dt3dr2, dt3dr2, ArgInfo("dt3dr2", 1)) &&
        pyopencv_to(pyobj_dt3dt2, dt3dt2, ArgInfo("dt3dt2", 1)) )
    {
        ERRWRAP2(cv::composeRT(rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1, dr3dt1, dr3dr2, dr3dt2, dt3dr1, dt3dt1, dt3dr2, dt3dt2));
        return Py_BuildValue("(NNNNNNNNNN)", pyopencv_from(rvec3), pyopencv_from(tvec3), pyopencv_from(dr3dr1), pyopencv_from(dr3dt1), pyopencv_from(dr3dr2), pyopencv_from(dr3dt2), pyopencv_from(dt3dr1), pyopencv_from(dt3dt1), pyopencv_from(dt3dr2), pyopencv_from(dt3dt2));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_computeCorrespondEpilines(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    PyObject* pyobj_whichImage = NULL;
    int whichImage=0;
    PyObject* pyobj_F = NULL;
    Mat F;
    PyObject* pyobj_lines = NULL;
    Mat lines;

    const char* keywords[] = { "points", "whichImage", "F", "lines", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:computeCorrespondEpilines", (char**)keywords, &pyobj_points, &pyobj_whichImage, &pyobj_F, &pyobj_lines) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to(pyobj_whichImage, whichImage, ArgInfo("whichImage", 0)) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 0)) &&
        pyopencv_to(pyobj_lines, lines, ArgInfo("lines", 1)) )
    {
        ERRWRAP2(cv::computeCorrespondEpilines(points, whichImage, F, lines));
        return pyopencv_from(lines);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    PyObject* pyobj_whichImage = NULL;
    int whichImage=0;
    PyObject* pyobj_F = NULL;
    UMat F;
    PyObject* pyobj_lines = NULL;
    UMat lines;

    const char* keywords[] = { "points", "whichImage", "F", "lines", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:computeCorrespondEpilines", (char**)keywords, &pyobj_points, &pyobj_whichImage, &pyobj_F, &pyobj_lines) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to(pyobj_whichImage, whichImage, ArgInfo("whichImage", 0)) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 0)) &&
        pyopencv_to(pyobj_lines, lines, ArgInfo("lines", 1)) )
    {
        ERRWRAP2(cv::computeCorrespondEpilines(points, whichImage, F, lines));
        return pyopencv_from(lines);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_computeECC(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_templateImage = NULL;
    Mat templateImage;
    PyObject* pyobj_inputImage = NULL;
    Mat inputImage;
    PyObject* pyobj_inputMask = NULL;
    Mat inputMask;
    double retval;

    const char* keywords[] = { "templateImage", "inputImage", "inputMask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:computeECC", (char**)keywords, &pyobj_templateImage, &pyobj_inputImage, &pyobj_inputMask) &&
        pyopencv_to(pyobj_templateImage, templateImage, ArgInfo("templateImage", 0)) &&
        pyopencv_to(pyobj_inputImage, inputImage, ArgInfo("inputImage", 0)) &&
        pyopencv_to(pyobj_inputMask, inputMask, ArgInfo("inputMask", 0)) )
    {
        ERRWRAP2(retval = cv::computeECC(templateImage, inputImage, inputMask));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_templateImage = NULL;
    UMat templateImage;
    PyObject* pyobj_inputImage = NULL;
    UMat inputImage;
    PyObject* pyobj_inputMask = NULL;
    UMat inputMask;
    double retval;

    const char* keywords[] = { "templateImage", "inputImage", "inputMask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:computeECC", (char**)keywords, &pyobj_templateImage, &pyobj_inputImage, &pyobj_inputMask) &&
        pyopencv_to(pyobj_templateImage, templateImage, ArgInfo("templateImage", 0)) &&
        pyopencv_to(pyobj_inputImage, inputImage, ArgInfo("inputImage", 0)) &&
        pyopencv_to(pyobj_inputMask, inputMask, ArgInfo("inputMask", 0)) )
    {
        ERRWRAP2(retval = cv::computeECC(templateImage, inputImage, inputMask));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_connectedComponents(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;
    int retval;

    const char* keywords[] = { "image", "labels", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:connectedComponents", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponents(image, labels, connectivity, ltype));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(labels));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;
    int retval;

    const char* keywords[] = { "image", "labels", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:connectedComponents", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponents(image, labels, connectivity, ltype));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(labels));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_connectedComponentsWithAlgorithm(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    int ccltype=0;
    int retval;

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:connectedComponentsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponents(image, labels, connectivity, ltype, ccltype));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(labels));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    int ccltype=0;
    int retval;

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:connectedComponentsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponents(image, labels, connectivity, ltype, ccltype));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(labels));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_connectedComponentsWithStats(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_stats = NULL;
    Mat stats;
    PyObject* pyobj_centroids = NULL;
    Mat centroids;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;
    int retval;

    const char* keywords[] = { "image", "labels", "stats", "centroids", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOO:connectedComponentsWithStats", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_stats, &pyobj_centroids, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to(pyobj_stats, stats, ArgInfo("stats", 1)) &&
        pyopencv_to(pyobj_centroids, centroids, ArgInfo("centroids", 1)) &&
        pyopencv_to(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponentsWithStats(image, labels, stats, centroids, connectivity, ltype));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(labels), pyopencv_from(stats), pyopencv_from(centroids));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_stats = NULL;
    UMat stats;
    PyObject* pyobj_centroids = NULL;
    UMat centroids;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;
    int retval;

    const char* keywords[] = { "image", "labels", "stats", "centroids", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOO:connectedComponentsWithStats", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_stats, &pyobj_centroids, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to(pyobj_stats, stats, ArgInfo("stats", 1)) &&
        pyopencv_to(pyobj_centroids, centroids, ArgInfo("centroids", 1)) &&
        pyopencv_to(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponentsWithStats(image, labels, stats, centroids, connectivity, ltype));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(labels), pyopencv_from(stats), pyopencv_from(centroids));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_connectedComponentsWithStatsWithAlgorithm(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_stats = NULL;
    Mat stats;
    PyObject* pyobj_centroids = NULL;
    Mat centroids;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    int ccltype=0;
    int retval;

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", "stats", "centroids", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:connectedComponentsWithStatsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels, &pyobj_stats, &pyobj_centroids) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to(pyobj_stats, stats, ArgInfo("stats", 1)) &&
        pyopencv_to(pyobj_centroids, centroids, ArgInfo("centroids", 1)) &&
        pyopencv_to(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponentsWithStats(image, labels, stats, centroids, connectivity, ltype, ccltype));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(labels), pyopencv_from(stats), pyopencv_from(centroids));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_stats = NULL;
    UMat stats;
    PyObject* pyobj_centroids = NULL;
    UMat centroids;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    int ccltype=0;
    int retval;

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", "stats", "centroids", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:connectedComponentsWithStatsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels, &pyobj_stats, &pyobj_centroids) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to(pyobj_stats, stats, ArgInfo("stats", 1)) &&
        pyopencv_to(pyobj_centroids, centroids, ArgInfo("centroids", 1)) &&
        pyopencv_to(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponentsWithStats(image, labels, stats, centroids, connectivity, ltype, ccltype));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(labels), pyopencv_from(stats), pyopencv_from(centroids));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_contourArea(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_contour = NULL;
    Mat contour;
    PyObject* pyobj_oriented = NULL;
    bool oriented=false;
    double retval;

    const char* keywords[] = { "contour", "oriented", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:contourArea", (char**)keywords, &pyobj_contour, &pyobj_oriented) &&
        pyopencv_to(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to(pyobj_oriented, oriented, ArgInfo("oriented", 0)) )
    {
        ERRWRAP2(retval = cv::contourArea(contour, oriented));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_contour = NULL;
    UMat contour;
    PyObject* pyobj_oriented = NULL;
    bool oriented=false;
    double retval;

    const char* keywords[] = { "contour", "oriented", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:contourArea", (char**)keywords, &pyobj_contour, &pyobj_oriented) &&
        pyopencv_to(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to(pyobj_oriented, oriented, ArgInfo("oriented", 0)) )
    {
        ERRWRAP2(retval = cv::contourArea(contour, oriented));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_convertFp16(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:convertFp16", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::convertFp16(src, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:convertFp16", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::convertFp16(src, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_convertMaps(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_map1 = NULL;
    Mat map1;
    PyObject* pyobj_map2 = NULL;
    Mat map2;
    PyObject* pyobj_dstmap1 = NULL;
    Mat dstmap1;
    PyObject* pyobj_dstmap2 = NULL;
    Mat dstmap2;
    PyObject* pyobj_dstmap1type = NULL;
    int dstmap1type=0;
    PyObject* pyobj_nninterpolation = NULL;
    bool nninterpolation=false;

    const char* keywords[] = { "map1", "map2", "dstmap1type", "dstmap1", "dstmap2", "nninterpolation", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:convertMaps", (char**)keywords, &pyobj_map1, &pyobj_map2, &pyobj_dstmap1type, &pyobj_dstmap1, &pyobj_dstmap2, &pyobj_nninterpolation) &&
        pyopencv_to(pyobj_map1, map1, ArgInfo("map1", 0)) &&
        pyopencv_to(pyobj_map2, map2, ArgInfo("map2", 0)) &&
        pyopencv_to(pyobj_dstmap1, dstmap1, ArgInfo("dstmap1", 1)) &&
        pyopencv_to(pyobj_dstmap2, dstmap2, ArgInfo("dstmap2", 1)) &&
        pyopencv_to(pyobj_dstmap1type, dstmap1type, ArgInfo("dstmap1type", 0)) &&
        pyopencv_to(pyobj_nninterpolation, nninterpolation, ArgInfo("nninterpolation", 0)) )
    {
        ERRWRAP2(cv::convertMaps(map1, map2, dstmap1, dstmap2, dstmap1type, nninterpolation));
        return Py_BuildValue("(NN)", pyopencv_from(dstmap1), pyopencv_from(dstmap2));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_map1 = NULL;
    UMat map1;
    PyObject* pyobj_map2 = NULL;
    UMat map2;
    PyObject* pyobj_dstmap1 = NULL;
    UMat dstmap1;
    PyObject* pyobj_dstmap2 = NULL;
    UMat dstmap2;
    PyObject* pyobj_dstmap1type = NULL;
    int dstmap1type=0;
    PyObject* pyobj_nninterpolation = NULL;
    bool nninterpolation=false;

    const char* keywords[] = { "map1", "map2", "dstmap1type", "dstmap1", "dstmap2", "nninterpolation", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:convertMaps", (char**)keywords, &pyobj_map1, &pyobj_map2, &pyobj_dstmap1type, &pyobj_dstmap1, &pyobj_dstmap2, &pyobj_nninterpolation) &&
        pyopencv_to(pyobj_map1, map1, ArgInfo("map1", 0)) &&
        pyopencv_to(pyobj_map2, map2, ArgInfo("map2", 0)) &&
        pyopencv_to(pyobj_dstmap1, dstmap1, ArgInfo("dstmap1", 1)) &&
        pyopencv_to(pyobj_dstmap2, dstmap2, ArgInfo("dstmap2", 1)) &&
        pyopencv_to(pyobj_dstmap1type, dstmap1type, ArgInfo("dstmap1type", 0)) &&
        pyopencv_to(pyobj_nninterpolation, nninterpolation, ArgInfo("nninterpolation", 0)) )
    {
        ERRWRAP2(cv::convertMaps(map1, map2, dstmap1, dstmap2, dstmap1type, nninterpolation));
        return Py_BuildValue("(NN)", pyopencv_from(dstmap1), pyopencv_from(dstmap2));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_convertPointsFromHomogeneous(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:convertPointsFromHomogeneous", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::convertPointsFromHomogeneous(src, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:convertPointsFromHomogeneous", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::convertPointsFromHomogeneous(src, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_convertPointsToHomogeneous(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:convertPointsToHomogeneous", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::convertPointsToHomogeneous(src, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:convertPointsToHomogeneous", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::convertPointsToHomogeneous(src, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_convertScaleAbs(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=1;
    PyObject* pyobj_beta = NULL;
    double beta=0;

    const char* keywords[] = { "src", "dst", "alpha", "beta", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:convertScaleAbs", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_beta) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_beta, beta, ArgInfo("beta", 0)) )
    {
        ERRWRAP2(cv::convertScaleAbs(src, dst, alpha, beta));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=1;
    PyObject* pyobj_beta = NULL;
    double beta=0;

    const char* keywords[] = { "src", "dst", "alpha", "beta", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:convertScaleAbs", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_beta) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_beta, beta, ArgInfo("beta", 0)) )
    {
        ERRWRAP2(cv::convertScaleAbs(src, dst, alpha, beta));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_convexHull(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    PyObject* pyobj_hull = NULL;
    Mat hull;
    PyObject* pyobj_clockwise = NULL;
    bool clockwise=false;
    PyObject* pyobj_returnPoints = NULL;
    bool returnPoints=true;

    const char* keywords[] = { "points", "hull", "clockwise", "returnPoints", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:convexHull", (char**)keywords, &pyobj_points, &pyobj_hull, &pyobj_clockwise, &pyobj_returnPoints) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to(pyobj_hull, hull, ArgInfo("hull", 1)) &&
        pyopencv_to(pyobj_clockwise, clockwise, ArgInfo("clockwise", 0)) &&
        pyopencv_to(pyobj_returnPoints, returnPoints, ArgInfo("returnPoints", 0)) )
    {
        ERRWRAP2(cv::convexHull(points, hull, clockwise, returnPoints));
        return pyopencv_from(hull);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    PyObject* pyobj_hull = NULL;
    UMat hull;
    PyObject* pyobj_clockwise = NULL;
    bool clockwise=false;
    PyObject* pyobj_returnPoints = NULL;
    bool returnPoints=true;

    const char* keywords[] = { "points", "hull", "clockwise", "returnPoints", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:convexHull", (char**)keywords, &pyobj_points, &pyobj_hull, &pyobj_clockwise, &pyobj_returnPoints) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to(pyobj_hull, hull, ArgInfo("hull", 1)) &&
        pyopencv_to(pyobj_clockwise, clockwise, ArgInfo("clockwise", 0)) &&
        pyopencv_to(pyobj_returnPoints, returnPoints, ArgInfo("returnPoints", 0)) )
    {
        ERRWRAP2(cv::convexHull(points, hull, clockwise, returnPoints));
        return pyopencv_from(hull);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_convexityDefects(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_contour = NULL;
    Mat contour;
    PyObject* pyobj_convexhull = NULL;
    Mat convexhull;
    PyObject* pyobj_convexityDefects = NULL;
    Mat convexityDefects;

    const char* keywords[] = { "contour", "convexhull", "convexityDefects", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:convexityDefects", (char**)keywords, &pyobj_contour, &pyobj_convexhull, &pyobj_convexityDefects) &&
        pyopencv_to(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to(pyobj_convexhull, convexhull, ArgInfo("convexhull", 0)) &&
        pyopencv_to(pyobj_convexityDefects, convexityDefects, ArgInfo("convexityDefects", 1)) )
    {
        ERRWRAP2(cv::convexityDefects(contour, convexhull, convexityDefects));
        return pyopencv_from(convexityDefects);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_contour = NULL;
    UMat contour;
    PyObject* pyobj_convexhull = NULL;
    UMat convexhull;
    PyObject* pyobj_convexityDefects = NULL;
    UMat convexityDefects;

    const char* keywords[] = { "contour", "convexhull", "convexityDefects", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:convexityDefects", (char**)keywords, &pyobj_contour, &pyobj_convexhull, &pyobj_convexityDefects) &&
        pyopencv_to(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to(pyobj_convexhull, convexhull, ArgInfo("convexhull", 0)) &&
        pyopencv_to(pyobj_convexityDefects, convexityDefects, ArgInfo("convexityDefects", 1)) )
    {
        ERRWRAP2(cv::convexityDefects(contour, convexhull, convexityDefects));
        return pyopencv_from(convexityDefects);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_copyMakeBorder(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_top = NULL;
    int top=0;
    PyObject* pyobj_bottom = NULL;
    int bottom=0;
    PyObject* pyobj_left = NULL;
    int left=0;
    PyObject* pyobj_right = NULL;
    int right=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=0;
    PyObject* pyobj_value = NULL;
    Scalar value;

    const char* keywords[] = { "src", "top", "bottom", "left", "right", "borderType", "dst", "value", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OO:copyMakeBorder", (char**)keywords, &pyobj_src, &pyobj_top, &pyobj_bottom, &pyobj_left, &pyobj_right, &pyobj_borderType, &pyobj_dst, &pyobj_value) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_top, top, ArgInfo("top", 0)) &&
        pyopencv_to(pyobj_bottom, bottom, ArgInfo("bottom", 0)) &&
        pyopencv_to(pyobj_left, left, ArgInfo("left", 0)) &&
        pyopencv_to(pyobj_right, right, ArgInfo("right", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to(pyobj_value, value, ArgInfo("value", 0)) )
    {
        ERRWRAP2(cv::copyMakeBorder(src, dst, top, bottom, left, right, borderType, value));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_top = NULL;
    int top=0;
    PyObject* pyobj_bottom = NULL;
    int bottom=0;
    PyObject* pyobj_left = NULL;
    int left=0;
    PyObject* pyobj_right = NULL;
    int right=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=0;
    PyObject* pyobj_value = NULL;
    Scalar value;

    const char* keywords[] = { "src", "top", "bottom", "left", "right", "borderType", "dst", "value", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OO:copyMakeBorder", (char**)keywords, &pyobj_src, &pyobj_top, &pyobj_bottom, &pyobj_left, &pyobj_right, &pyobj_borderType, &pyobj_dst, &pyobj_value) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_top, top, ArgInfo("top", 0)) &&
        pyopencv_to(pyobj_bottom, bottom, ArgInfo("bottom", 0)) &&
        pyopencv_to(pyobj_left, left, ArgInfo("left", 0)) &&
        pyopencv_to(pyobj_right, right, ArgInfo("right", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to(pyobj_value, value, ArgInfo("value", 0)) )
    {
        ERRWRAP2(cv::copyMakeBorder(src, dst, top, bottom, left, right, borderType, value));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_copyTo(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "mask", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:copyTo", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::copyTo(src, dst, mask));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "mask", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:copyTo", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::copyTo(src, dst, mask));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_cornerEigenValsAndVecs(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "ksize", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:cornerEigenValsAndVecs", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_ksize, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerEigenValsAndVecs(src, dst, blockSize, ksize, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "ksize", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:cornerEigenValsAndVecs", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_ksize, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerEigenValsAndVecs(src, dst, blockSize, ksize, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_cornerHarris(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_k = NULL;
    double k=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "ksize", "k", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:cornerHarris", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_ksize, &pyobj_k, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_k, k, ArgInfo("k", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerHarris(src, dst, blockSize, ksize, k, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_k = NULL;
    double k=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "ksize", "k", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:cornerHarris", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_ksize, &pyobj_k, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_k, k, ArgInfo("k", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerHarris(src, dst, blockSize, ksize, k, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_cornerMinEigenVal(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "dst", "ksize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:cornerMinEigenVal", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_dst, &pyobj_ksize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerMinEigenVal(src, dst, blockSize, ksize, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "dst", "ksize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:cornerMinEigenVal", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_dst, &pyobj_ksize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerMinEigenVal(src, dst, blockSize, ksize, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_cornerSubPix(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_winSize = NULL;
    Size winSize;
    PyObject* pyobj_zeroZone = NULL;
    Size zeroZone;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;

    const char* keywords[] = { "image", "corners", "winSize", "zeroZone", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO:cornerSubPix", (char**)keywords, &pyobj_image, &pyobj_corners, &pyobj_winSize, &pyobj_zeroZone, &pyobj_criteria) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to(pyobj_zeroZone, zeroZone, ArgInfo("zeroZone", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(cv::cornerSubPix(image, corners, winSize, zeroZone, criteria));
        return pyopencv_from(corners);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_winSize = NULL;
    Size winSize;
    PyObject* pyobj_zeroZone = NULL;
    Size zeroZone;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;

    const char* keywords[] = { "image", "corners", "winSize", "zeroZone", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO:cornerSubPix", (char**)keywords, &pyobj_image, &pyobj_corners, &pyobj_winSize, &pyobj_zeroZone, &pyobj_criteria) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to(pyobj_zeroZone, zeroZone, ArgInfo("zeroZone", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(cv::cornerSubPix(image, corners, winSize, zeroZone, criteria));
        return pyopencv_from(corners);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_correctMatches(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_F = NULL;
    Mat F;
    PyObject* pyobj_points1 = NULL;
    Mat points1;
    PyObject* pyobj_points2 = NULL;
    Mat points2;
    PyObject* pyobj_newPoints1 = NULL;
    Mat newPoints1;
    PyObject* pyobj_newPoints2 = NULL;
    Mat newPoints2;

    const char* keywords[] = { "F", "points1", "points2", "newPoints1", "newPoints2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:correctMatches", (char**)keywords, &pyobj_F, &pyobj_points1, &pyobj_points2, &pyobj_newPoints1, &pyobj_newPoints2) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 0)) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_newPoints1, newPoints1, ArgInfo("newPoints1", 1)) &&
        pyopencv_to(pyobj_newPoints2, newPoints2, ArgInfo("newPoints2", 1)) )
    {
        ERRWRAP2(cv::correctMatches(F, points1, points2, newPoints1, newPoints2));
        return Py_BuildValue("(NN)", pyopencv_from(newPoints1), pyopencv_from(newPoints2));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_F = NULL;
    UMat F;
    PyObject* pyobj_points1 = NULL;
    UMat points1;
    PyObject* pyobj_points2 = NULL;
    UMat points2;
    PyObject* pyobj_newPoints1 = NULL;
    UMat newPoints1;
    PyObject* pyobj_newPoints2 = NULL;
    UMat newPoints2;

    const char* keywords[] = { "F", "points1", "points2", "newPoints1", "newPoints2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:correctMatches", (char**)keywords, &pyobj_F, &pyobj_points1, &pyobj_points2, &pyobj_newPoints1, &pyobj_newPoints2) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 0)) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_newPoints1, newPoints1, ArgInfo("newPoints1", 1)) &&
        pyopencv_to(pyobj_newPoints2, newPoints2, ArgInfo("newPoints2", 1)) )
    {
        ERRWRAP2(cv::correctMatches(F, points1, points2, newPoints1, newPoints2));
        return Py_BuildValue("(NN)", pyopencv_from(newPoints1), pyopencv_from(newPoints2));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_countNonZero(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    int retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:countNonZero", (char**)keywords, &pyobj_src) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::countNonZero(src));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    int retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:countNonZero", (char**)keywords, &pyobj_src) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::countNonZero(src));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_createAlignMTB(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_max_bits = NULL;
    int max_bits=6;
    PyObject* pyobj_exclude_range = NULL;
    int exclude_range=4;
    PyObject* pyobj_cut = NULL;
    bool cut=true;
    Ptr<AlignMTB> retval;

    const char* keywords[] = { "max_bits", "exclude_range", "cut", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:createAlignMTB", (char**)keywords, &pyobj_max_bits, &pyobj_exclude_range, &pyobj_cut) &&
        pyopencv_to(pyobj_max_bits, max_bits, ArgInfo("max_bits", 0)) &&
        pyopencv_to(pyobj_exclude_range, exclude_range, ArgInfo("exclude_range", 0)) &&
        pyopencv_to(pyobj_cut, cut, ArgInfo("cut", 0)) )
    {
        ERRWRAP2(retval = cv::createAlignMTB(max_bits, exclude_range, cut));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createBackgroundSubtractorKNN(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_history = NULL;
    int history=500;
    PyObject* pyobj_dist2Threshold = NULL;
    double dist2Threshold=400.0;
    PyObject* pyobj_detectShadows = NULL;
    bool detectShadows=true;
    Ptr<BackgroundSubtractorKNN> retval;

    const char* keywords[] = { "history", "dist2Threshold", "detectShadows", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:createBackgroundSubtractorKNN", (char**)keywords, &pyobj_history, &pyobj_dist2Threshold, &pyobj_detectShadows) &&
        pyopencv_to(pyobj_history, history, ArgInfo("history", 0)) &&
        pyopencv_to(pyobj_dist2Threshold, dist2Threshold, ArgInfo("dist2Threshold", 0)) &&
        pyopencv_to(pyobj_detectShadows, detectShadows, ArgInfo("detectShadows", 0)) )
    {
        ERRWRAP2(retval = cv::createBackgroundSubtractorKNN(history, dist2Threshold, detectShadows));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createBackgroundSubtractorMOG2(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_history = NULL;
    int history=500;
    PyObject* pyobj_varThreshold = NULL;
    double varThreshold=16;
    PyObject* pyobj_detectShadows = NULL;
    bool detectShadows=true;
    Ptr<BackgroundSubtractorMOG2> retval;

    const char* keywords[] = { "history", "varThreshold", "detectShadows", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:createBackgroundSubtractorMOG2", (char**)keywords, &pyobj_history, &pyobj_varThreshold, &pyobj_detectShadows) &&
        pyopencv_to(pyobj_history, history, ArgInfo("history", 0)) &&
        pyopencv_to(pyobj_varThreshold, varThreshold, ArgInfo("varThreshold", 0)) &&
        pyopencv_to(pyobj_detectShadows, detectShadows, ArgInfo("detectShadows", 0)) )
    {
        ERRWRAP2(retval = cv::createBackgroundSubtractorMOG2(history, varThreshold, detectShadows));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createCLAHE(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_clipLimit = NULL;
    double clipLimit=40.0;
    PyObject* pyobj_tileGridSize = NULL;
    Size tileGridSize=Size(8, 8);
    Ptr<CLAHE> retval;

    const char* keywords[] = { "clipLimit", "tileGridSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OO:createCLAHE", (char**)keywords, &pyobj_clipLimit, &pyobj_tileGridSize) &&
        pyopencv_to(pyobj_clipLimit, clipLimit, ArgInfo("clipLimit", 0)) &&
        pyopencv_to(pyobj_tileGridSize, tileGridSize, ArgInfo("tileGridSize", 0)) )
    {
        ERRWRAP2(retval = cv::createCLAHE(clipLimit, tileGridSize));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createCalibrateDebevec(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_samples = NULL;
    int samples=70;
    PyObject* pyobj_lambda = NULL;
    float lambda=10.0f;
    PyObject* pyobj_random = NULL;
    bool random=false;
    Ptr<CalibrateDebevec> retval;

    const char* keywords[] = { "samples", "lambda", "random", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:createCalibrateDebevec", (char**)keywords, &pyobj_samples, &pyobj_lambda, &pyobj_random) &&
        pyopencv_to(pyobj_samples, samples, ArgInfo("samples", 0)) &&
        pyopencv_to(pyobj_lambda, lambda, ArgInfo("lambda", 0)) &&
        pyopencv_to(pyobj_random, random, ArgInfo("random", 0)) )
    {
        ERRWRAP2(retval = cv::createCalibrateDebevec(samples, lambda, random));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createCalibrateRobertson(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_max_iter = NULL;
    int max_iter=30;
    PyObject* pyobj_threshold = NULL;
    float threshold=0.01f;
    Ptr<CalibrateRobertson> retval;

    const char* keywords[] = { "max_iter", "threshold", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OO:createCalibrateRobertson", (char**)keywords, &pyobj_max_iter, &pyobj_threshold) &&
        pyopencv_to(pyobj_max_iter, max_iter, ArgInfo("max_iter", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) )
    {
        ERRWRAP2(retval = cv::createCalibrateRobertson(max_iter, threshold));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createGeneralizedHoughBallard(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    Ptr<GeneralizedHoughBallard> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::createGeneralizedHoughBallard());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createGeneralizedHoughGuil(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    Ptr<GeneralizedHoughGuil> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::createGeneralizedHoughGuil());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createHanningWindow(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_winSize = NULL;
    Size winSize;
    PyObject* pyobj_type = NULL;
    int type=0;

    const char* keywords[] = { "winSize", "type", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:createHanningWindow", (char**)keywords, &pyobj_winSize, &pyobj_type, &pyobj_dst) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(cv::createHanningWindow(dst, winSize, type));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_winSize = NULL;
    Size winSize;
    PyObject* pyobj_type = NULL;
    int type=0;

    const char* keywords[] = { "winSize", "type", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:createHanningWindow", (char**)keywords, &pyobj_winSize, &pyobj_type, &pyobj_dst) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(cv::createHanningWindow(dst, winSize, type));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_createLineSegmentDetector(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj__refine = NULL;
    int _refine=LSD_REFINE_STD;
    PyObject* pyobj__scale = NULL;
    double _scale=0.8;
    PyObject* pyobj__sigma_scale = NULL;
    double _sigma_scale=0.6;
    PyObject* pyobj__quant = NULL;
    double _quant=2.0;
    PyObject* pyobj__ang_th = NULL;
    double _ang_th=22.5;
    PyObject* pyobj__log_eps = NULL;
    double _log_eps=0;
    PyObject* pyobj__density_th = NULL;
    double _density_th=0.7;
    PyObject* pyobj__n_bins = NULL;
    int _n_bins=1024;
    Ptr<LineSegmentDetector> retval;

    const char* keywords[] = { "_refine", "_scale", "_sigma_scale", "_quant", "_ang_th", "_log_eps", "_density_th", "_n_bins", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOOOOOO:createLineSegmentDetector", (char**)keywords, &pyobj__refine, &pyobj__scale, &pyobj__sigma_scale, &pyobj__quant, &pyobj__ang_th, &pyobj__log_eps, &pyobj__density_th, &pyobj__n_bins) &&
        pyopencv_to(pyobj__refine, _refine, ArgInfo("_refine", 0)) &&
        pyopencv_to(pyobj__scale, _scale, ArgInfo("_scale", 0)) &&
        pyopencv_to(pyobj__sigma_scale, _sigma_scale, ArgInfo("_sigma_scale", 0)) &&
        pyopencv_to(pyobj__quant, _quant, ArgInfo("_quant", 0)) &&
        pyopencv_to(pyobj__ang_th, _ang_th, ArgInfo("_ang_th", 0)) &&
        pyopencv_to(pyobj__log_eps, _log_eps, ArgInfo("_log_eps", 0)) &&
        pyopencv_to(pyobj__density_th, _density_th, ArgInfo("_density_th", 0)) &&
        pyopencv_to(pyobj__n_bins, _n_bins, ArgInfo("_n_bins", 0)) )
    {
        ERRWRAP2(retval = cv::createLineSegmentDetector(_refine, _scale, _sigma_scale, _quant, _ang_th, _log_eps, _density_th, _n_bins));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createMergeDebevec(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    Ptr<MergeDebevec> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::createMergeDebevec());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createMergeMertens(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_contrast_weight = NULL;
    float contrast_weight=1.0f;
    PyObject* pyobj_saturation_weight = NULL;
    float saturation_weight=1.0f;
    PyObject* pyobj_exposure_weight = NULL;
    float exposure_weight=0.0f;
    Ptr<MergeMertens> retval;

    const char* keywords[] = { "contrast_weight", "saturation_weight", "exposure_weight", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:createMergeMertens", (char**)keywords, &pyobj_contrast_weight, &pyobj_saturation_weight, &pyobj_exposure_weight) &&
        pyopencv_to(pyobj_contrast_weight, contrast_weight, ArgInfo("contrast_weight", 0)) &&
        pyopencv_to(pyobj_saturation_weight, saturation_weight, ArgInfo("saturation_weight", 0)) &&
        pyopencv_to(pyobj_exposure_weight, exposure_weight, ArgInfo("exposure_weight", 0)) )
    {
        ERRWRAP2(retval = cv::createMergeMertens(contrast_weight, saturation_weight, exposure_weight));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createMergeRobertson(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    Ptr<MergeRobertson> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::createMergeRobertson());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createTonemap(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_gamma = NULL;
    float gamma=1.0f;
    Ptr<Tonemap> retval;

    const char* keywords[] = { "gamma", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|O:createTonemap", (char**)keywords, &pyobj_gamma) &&
        pyopencv_to(pyobj_gamma, gamma, ArgInfo("gamma", 0)) )
    {
        ERRWRAP2(retval = cv::createTonemap(gamma));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createTonemapDrago(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_gamma = NULL;
    float gamma=1.0f;
    PyObject* pyobj_saturation = NULL;
    float saturation=1.0f;
    PyObject* pyobj_bias = NULL;
    float bias=0.85f;
    Ptr<TonemapDrago> retval;

    const char* keywords[] = { "gamma", "saturation", "bias", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:createTonemapDrago", (char**)keywords, &pyobj_gamma, &pyobj_saturation, &pyobj_bias) &&
        pyopencv_to(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to(pyobj_saturation, saturation, ArgInfo("saturation", 0)) &&
        pyopencv_to(pyobj_bias, bias, ArgInfo("bias", 0)) )
    {
        ERRWRAP2(retval = cv::createTonemapDrago(gamma, saturation, bias));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createTonemapMantiuk(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_gamma = NULL;
    float gamma=1.0f;
    PyObject* pyobj_scale = NULL;
    float scale=0.7f;
    PyObject* pyobj_saturation = NULL;
    float saturation=1.0f;
    Ptr<TonemapMantiuk> retval;

    const char* keywords[] = { "gamma", "scale", "saturation", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:createTonemapMantiuk", (char**)keywords, &pyobj_gamma, &pyobj_scale, &pyobj_saturation) &&
        pyopencv_to(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_saturation, saturation, ArgInfo("saturation", 0)) )
    {
        ERRWRAP2(retval = cv::createTonemapMantiuk(gamma, scale, saturation));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createTonemapReinhard(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_gamma = NULL;
    float gamma=1.0f;
    PyObject* pyobj_intensity = NULL;
    float intensity=0.0f;
    PyObject* pyobj_light_adapt = NULL;
    float light_adapt=1.0f;
    PyObject* pyobj_color_adapt = NULL;
    float color_adapt=0.0f;
    Ptr<TonemapReinhard> retval;

    const char* keywords[] = { "gamma", "intensity", "light_adapt", "color_adapt", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOO:createTonemapReinhard", (char**)keywords, &pyobj_gamma, &pyobj_intensity, &pyobj_light_adapt, &pyobj_color_adapt) &&
        pyopencv_to(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to(pyobj_intensity, intensity, ArgInfo("intensity", 0)) &&
        pyopencv_to(pyobj_light_adapt, light_adapt, ArgInfo("light_adapt", 0)) &&
        pyopencv_to(pyobj_color_adapt, color_adapt, ArgInfo("color_adapt", 0)) )
    {
        ERRWRAP2(retval = cv::createTonemapReinhard(gamma, intensity, light_adapt, color_adapt));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cubeRoot(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_val = NULL;
    float val=0.f;
    float retval;

    const char* keywords[] = { "val", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:cubeRoot", (char**)keywords, &pyobj_val) &&
        pyopencv_to(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(retval = cv::cubeRoot(val));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cvtColor(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dstCn = NULL;
    int dstCn=0;

    const char* keywords[] = { "src", "code", "dst", "dstCn", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:cvtColor", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dstCn) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to(pyobj_dstCn, dstCn, ArgInfo("dstCn", 0)) )
    {
        ERRWRAP2(cv::cvtColor(src, dst, code, dstCn));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dstCn = NULL;
    int dstCn=0;

    const char* keywords[] = { "src", "code", "dst", "dstCn", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:cvtColor", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dstCn) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to(pyobj_dstCn, dstCn, ArgInfo("dstCn", 0)) )
    {
        ERRWRAP2(cv::cvtColor(src, dst, code, dstCn));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_cvtColorTwoPlane(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_code = NULL;
    int code=0;

    const char* keywords[] = { "src1", "src2", "code", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:cvtColorTwoPlane", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_code, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_code, code, ArgInfo("code", 0)) )
    {
        ERRWRAP2(cv::cvtColorTwoPlane(src1, src2, dst, code));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_code = NULL;
    int code=0;

    const char* keywords[] = { "src1", "src2", "code", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:cvtColorTwoPlane", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_code, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_code, code, ArgInfo("code", 0)) )
    {
        ERRWRAP2(cv::cvtColorTwoPlane(src1, src2, dst, code));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dct(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:dct", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::dct(src, dst, flags));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:dct", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::dct(src, dst, flags));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_decolor(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_grayscale = NULL;
    Mat grayscale;
    PyObject* pyobj_color_boost = NULL;
    Mat color_boost;

    const char* keywords[] = { "src", "grayscale", "color_boost", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:decolor", (char**)keywords, &pyobj_src, &pyobj_grayscale, &pyobj_color_boost) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_grayscale, grayscale, ArgInfo("grayscale", 1)) &&
        pyopencv_to(pyobj_color_boost, color_boost, ArgInfo("color_boost", 1)) )
    {
        ERRWRAP2(cv::decolor(src, grayscale, color_boost));
        return Py_BuildValue("(NN)", pyopencv_from(grayscale), pyopencv_from(color_boost));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_grayscale = NULL;
    UMat grayscale;
    PyObject* pyobj_color_boost = NULL;
    UMat color_boost;

    const char* keywords[] = { "src", "grayscale", "color_boost", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:decolor", (char**)keywords, &pyobj_src, &pyobj_grayscale, &pyobj_color_boost) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_grayscale, grayscale, ArgInfo("grayscale", 1)) &&
        pyopencv_to(pyobj_color_boost, color_boost, ArgInfo("color_boost", 1)) )
    {
        ERRWRAP2(cv::decolor(src, grayscale, color_boost));
        return Py_BuildValue("(NN)", pyopencv_from(grayscale), pyopencv_from(color_boost));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_decomposeEssentialMat(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_E = NULL;
    Mat E;
    PyObject* pyobj_R1 = NULL;
    Mat R1;
    PyObject* pyobj_R2 = NULL;
    Mat R2;
    PyObject* pyobj_t = NULL;
    Mat t;

    const char* keywords[] = { "E", "R1", "R2", "t", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:decomposeEssentialMat", (char**)keywords, &pyobj_E, &pyobj_R1, &pyobj_R2, &pyobj_t) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 0)) &&
        pyopencv_to(pyobj_R1, R1, ArgInfo("R1", 1)) &&
        pyopencv_to(pyobj_R2, R2, ArgInfo("R2", 1)) &&
        pyopencv_to(pyobj_t, t, ArgInfo("t", 1)) )
    {
        ERRWRAP2(cv::decomposeEssentialMat(E, R1, R2, t));
        return Py_BuildValue("(NNN)", pyopencv_from(R1), pyopencv_from(R2), pyopencv_from(t));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_E = NULL;
    UMat E;
    PyObject* pyobj_R1 = NULL;
    UMat R1;
    PyObject* pyobj_R2 = NULL;
    UMat R2;
    PyObject* pyobj_t = NULL;
    UMat t;

    const char* keywords[] = { "E", "R1", "R2", "t", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:decomposeEssentialMat", (char**)keywords, &pyobj_E, &pyobj_R1, &pyobj_R2, &pyobj_t) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 0)) &&
        pyopencv_to(pyobj_R1, R1, ArgInfo("R1", 1)) &&
        pyopencv_to(pyobj_R2, R2, ArgInfo("R2", 1)) &&
        pyopencv_to(pyobj_t, t, ArgInfo("t", 1)) )
    {
        ERRWRAP2(cv::decomposeEssentialMat(E, R1, R2, t));
        return Py_BuildValue("(NNN)", pyopencv_from(R1), pyopencv_from(R2), pyopencv_from(t));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_decomposeHomographyMat(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_H = NULL;
    Mat H;
    PyObject* pyobj_K = NULL;
    Mat K;
    PyObject* pyobj_rotations = NULL;
    vector_Mat rotations;
    PyObject* pyobj_translations = NULL;
    vector_Mat translations;
    PyObject* pyobj_normals = NULL;
    vector_Mat normals;
    int retval;

    const char* keywords[] = { "H", "K", "rotations", "translations", "normals", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:decomposeHomographyMat", (char**)keywords, &pyobj_H, &pyobj_K, &pyobj_rotations, &pyobj_translations, &pyobj_normals) &&
        pyopencv_to(pyobj_H, H, ArgInfo("H", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_rotations, rotations, ArgInfo("rotations", 1)) &&
        pyopencv_to(pyobj_translations, translations, ArgInfo("translations", 1)) &&
        pyopencv_to(pyobj_normals, normals, ArgInfo("normals", 1)) )
    {
        ERRWRAP2(retval = cv::decomposeHomographyMat(H, K, rotations, translations, normals));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(rotations), pyopencv_from(translations), pyopencv_from(normals));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_H = NULL;
    UMat H;
    PyObject* pyobj_K = NULL;
    UMat K;
    PyObject* pyobj_rotations = NULL;
    vector_UMat rotations;
    PyObject* pyobj_translations = NULL;
    vector_UMat translations;
    PyObject* pyobj_normals = NULL;
    vector_UMat normals;
    int retval;

    const char* keywords[] = { "H", "K", "rotations", "translations", "normals", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:decomposeHomographyMat", (char**)keywords, &pyobj_H, &pyobj_K, &pyobj_rotations, &pyobj_translations, &pyobj_normals) &&
        pyopencv_to(pyobj_H, H, ArgInfo("H", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_rotations, rotations, ArgInfo("rotations", 1)) &&
        pyopencv_to(pyobj_translations, translations, ArgInfo("translations", 1)) &&
        pyopencv_to(pyobj_normals, normals, ArgInfo("normals", 1)) )
    {
        ERRWRAP2(retval = cv::decomposeHomographyMat(H, K, rotations, translations, normals));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(rotations), pyopencv_from(translations), pyopencv_from(normals));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_decomposeProjectionMatrix(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_projMatrix = NULL;
    Mat projMatrix;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_rotMatrix = NULL;
    Mat rotMatrix;
    PyObject* pyobj_transVect = NULL;
    Mat transVect;
    PyObject* pyobj_rotMatrixX = NULL;
    Mat rotMatrixX;
    PyObject* pyobj_rotMatrixY = NULL;
    Mat rotMatrixY;
    PyObject* pyobj_rotMatrixZ = NULL;
    Mat rotMatrixZ;
    PyObject* pyobj_eulerAngles = NULL;
    Mat eulerAngles;

    const char* keywords[] = { "projMatrix", "cameraMatrix", "rotMatrix", "transVect", "rotMatrixX", "rotMatrixY", "rotMatrixZ", "eulerAngles", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOOOO:decomposeProjectionMatrix", (char**)keywords, &pyobj_projMatrix, &pyobj_cameraMatrix, &pyobj_rotMatrix, &pyobj_transVect, &pyobj_rotMatrixX, &pyobj_rotMatrixY, &pyobj_rotMatrixZ, &pyobj_eulerAngles) &&
        pyopencv_to(pyobj_projMatrix, projMatrix, ArgInfo("projMatrix", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 1)) &&
        pyopencv_to(pyobj_rotMatrix, rotMatrix, ArgInfo("rotMatrix", 1)) &&
        pyopencv_to(pyobj_transVect, transVect, ArgInfo("transVect", 1)) &&
        pyopencv_to(pyobj_rotMatrixX, rotMatrixX, ArgInfo("rotMatrixX", 1)) &&
        pyopencv_to(pyobj_rotMatrixY, rotMatrixY, ArgInfo("rotMatrixY", 1)) &&
        pyopencv_to(pyobj_rotMatrixZ, rotMatrixZ, ArgInfo("rotMatrixZ", 1)) &&
        pyopencv_to(pyobj_eulerAngles, eulerAngles, ArgInfo("eulerAngles", 1)) )
    {
        ERRWRAP2(cv::decomposeProjectionMatrix(projMatrix, cameraMatrix, rotMatrix, transVect, rotMatrixX, rotMatrixY, rotMatrixZ, eulerAngles));
        return Py_BuildValue("(NNNNNNN)", pyopencv_from(cameraMatrix), pyopencv_from(rotMatrix), pyopencv_from(transVect), pyopencv_from(rotMatrixX), pyopencv_from(rotMatrixY), pyopencv_from(rotMatrixZ), pyopencv_from(eulerAngles));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_projMatrix = NULL;
    UMat projMatrix;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_rotMatrix = NULL;
    UMat rotMatrix;
    PyObject* pyobj_transVect = NULL;
    UMat transVect;
    PyObject* pyobj_rotMatrixX = NULL;
    UMat rotMatrixX;
    PyObject* pyobj_rotMatrixY = NULL;
    UMat rotMatrixY;
    PyObject* pyobj_rotMatrixZ = NULL;
    UMat rotMatrixZ;
    PyObject* pyobj_eulerAngles = NULL;
    UMat eulerAngles;

    const char* keywords[] = { "projMatrix", "cameraMatrix", "rotMatrix", "transVect", "rotMatrixX", "rotMatrixY", "rotMatrixZ", "eulerAngles", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOOOO:decomposeProjectionMatrix", (char**)keywords, &pyobj_projMatrix, &pyobj_cameraMatrix, &pyobj_rotMatrix, &pyobj_transVect, &pyobj_rotMatrixX, &pyobj_rotMatrixY, &pyobj_rotMatrixZ, &pyobj_eulerAngles) &&
        pyopencv_to(pyobj_projMatrix, projMatrix, ArgInfo("projMatrix", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 1)) &&
        pyopencv_to(pyobj_rotMatrix, rotMatrix, ArgInfo("rotMatrix", 1)) &&
        pyopencv_to(pyobj_transVect, transVect, ArgInfo("transVect", 1)) &&
        pyopencv_to(pyobj_rotMatrixX, rotMatrixX, ArgInfo("rotMatrixX", 1)) &&
        pyopencv_to(pyobj_rotMatrixY, rotMatrixY, ArgInfo("rotMatrixY", 1)) &&
        pyopencv_to(pyobj_rotMatrixZ, rotMatrixZ, ArgInfo("rotMatrixZ", 1)) &&
        pyopencv_to(pyobj_eulerAngles, eulerAngles, ArgInfo("eulerAngles", 1)) )
    {
        ERRWRAP2(cv::decomposeProjectionMatrix(projMatrix, cameraMatrix, rotMatrix, transVect, rotMatrixX, rotMatrixY, rotMatrixZ, eulerAngles));
        return Py_BuildValue("(NNNNNNN)", pyopencv_from(cameraMatrix), pyopencv_from(rotMatrix), pyopencv_from(transVect), pyopencv_from(rotMatrixX), pyopencv_from(rotMatrixY), pyopencv_from(rotMatrixZ), pyopencv_from(eulerAngles));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_demosaicing(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dstCn = NULL;
    int dstCn=0;

    const char* keywords[] = { "src", "code", "dst", "dstCn", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:demosaicing", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dstCn) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to(pyobj_dstCn, dstCn, ArgInfo("dstCn", 0)) )
    {
        ERRWRAP2(cv::demosaicing(src, dst, code, dstCn));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dstCn = NULL;
    int dstCn=0;

    const char* keywords[] = { "src", "code", "dst", "dstCn", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:demosaicing", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dstCn) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to(pyobj_dstCn, dstCn, ArgInfo("dstCn", 0)) )
    {
        ERRWRAP2(cv::demosaicing(src, dst, code, dstCn));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_denoise_TVL1(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_observations = NULL;
    vector_Mat observations;
    PyObject* pyobj_result = NULL;
    Mat result;
    PyObject* pyobj_lambda = NULL;
    double lambda=1.0;
    PyObject* pyobj_niters = NULL;
    int niters=30;

    const char* keywords[] = { "observations", "result", "lambda", "niters", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:denoise_TVL1", (char**)keywords, &pyobj_observations, &pyobj_result, &pyobj_lambda, &pyobj_niters) &&
        pyopencv_to(pyobj_observations, observations, ArgInfo("observations", 0)) &&
        pyopencv_to(pyobj_result, result, ArgInfo("result", 0)) &&
        pyopencv_to(pyobj_lambda, lambda, ArgInfo("lambda", 0)) &&
        pyopencv_to(pyobj_niters, niters, ArgInfo("niters", 0)) )
    {
        ERRWRAP2(cv::denoise_TVL1(observations, result, lambda, niters));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_observations = NULL;
    vector_Mat observations;
    PyObject* pyobj_result = NULL;
    Mat result;
    PyObject* pyobj_lambda = NULL;
    double lambda=1.0;
    PyObject* pyobj_niters = NULL;
    int niters=30;

    const char* keywords[] = { "observations", "result", "lambda", "niters", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:denoise_TVL1", (char**)keywords, &pyobj_observations, &pyobj_result, &pyobj_lambda, &pyobj_niters) &&
        pyopencv_to(pyobj_observations, observations, ArgInfo("observations", 0)) &&
        pyopencv_to(pyobj_result, result, ArgInfo("result", 0)) &&
        pyopencv_to(pyobj_lambda, lambda, ArgInfo("lambda", 0)) &&
        pyopencv_to(pyobj_niters, niters, ArgInfo("niters", 0)) )
    {
        ERRWRAP2(cv::denoise_TVL1(observations, result, lambda, niters));
        Py_RETURN_NONE;
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_destroyAllWindows(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;


    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(cv::destroyAllWindows());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_destroyWindow(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_winname = NULL;
    String winname;

    const char* keywords[] = { "winname", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:destroyWindow", (char**)keywords, &pyobj_winname) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) )
    {
        ERRWRAP2(cv::destroyWindow(winname));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_detailEnhance(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_sigma_s = NULL;
    float sigma_s=10;
    PyObject* pyobj_sigma_r = NULL;
    float sigma_r=0.15f;

    const char* keywords[] = { "src", "dst", "sigma_s", "sigma_r", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:detailEnhance", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_sigma_s, &pyobj_sigma_r) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_sigma_s, sigma_s, ArgInfo("sigma_s", 0)) &&
        pyopencv_to(pyobj_sigma_r, sigma_r, ArgInfo("sigma_r", 0)) )
    {
        ERRWRAP2(cv::detailEnhance(src, dst, sigma_s, sigma_r));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_sigma_s = NULL;
    float sigma_s=10;
    PyObject* pyobj_sigma_r = NULL;
    float sigma_r=0.15f;

    const char* keywords[] = { "src", "dst", "sigma_s", "sigma_r", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:detailEnhance", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_sigma_s, &pyobj_sigma_r) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_sigma_s, sigma_s, ArgInfo("sigma_s", 0)) &&
        pyopencv_to(pyobj_sigma_r, sigma_r, ArgInfo("sigma_r", 0)) )
    {
        ERRWRAP2(cv::detailEnhance(src, dst, sigma_s, sigma_r));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_determinant(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_mtx = NULL;
    Mat mtx;
    double retval;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:determinant", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(retval = cv::determinant(mtx));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_mtx = NULL;
    UMat mtx;
    double retval;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:determinant", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(retval = cv::determinant(mtx));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dft(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_nonzeroRows = NULL;
    int nonzeroRows=0;

    const char* keywords[] = { "src", "dst", "flags", "nonzeroRows", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:dft", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags, &pyobj_nonzeroRows) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_nonzeroRows, nonzeroRows, ArgInfo("nonzeroRows", 0)) )
    {
        ERRWRAP2(cv::dft(src, dst, flags, nonzeroRows));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_nonzeroRows = NULL;
    int nonzeroRows=0;

    const char* keywords[] = { "src", "dst", "flags", "nonzeroRows", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:dft", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags, &pyobj_nonzeroRows) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_nonzeroRows, nonzeroRows, ArgInfo("nonzeroRows", 0)) )
    {
        ERRWRAP2(cv::dft(src, dst, flags, nonzeroRows));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dilate(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_kernel = NULL;
    Mat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOO:dilate", (char**)keywords, &pyobj_src, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::dilate(src, dst, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_kernel = NULL;
    UMat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOO:dilate", (char**)keywords, &pyobj_src, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::dilate(src, dst, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_displayOverlay(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_text = NULL;
    String text;
    PyObject* pyobj_delayms = NULL;
    int delayms=0;

    const char* keywords[] = { "winname", "text", "delayms", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:displayOverlay", (char**)keywords, &pyobj_winname, &pyobj_text, &pyobj_delayms) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_text, text, ArgInfo("text", 0)) &&
        pyopencv_to(pyobj_delayms, delayms, ArgInfo("delayms", 0)) )
    {
        ERRWRAP2(cv::displayOverlay(winname, text, delayms));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_displayStatusBar(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_text = NULL;
    String text;
    PyObject* pyobj_delayms = NULL;
    int delayms=0;

    const char* keywords[] = { "winname", "text", "delayms", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:displayStatusBar", (char**)keywords, &pyobj_winname, &pyobj_text, &pyobj_delayms) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_text, text, ArgInfo("text", 0)) &&
        pyopencv_to(pyobj_delayms, delayms, ArgInfo("delayms", 0)) )
    {
        ERRWRAP2(cv::displayStatusBar(winname, text, delayms));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_distanceTransform(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_distanceType = NULL;
    int distanceType=0;
    PyObject* pyobj_maskSize = NULL;
    int maskSize=0;
    PyObject* pyobj_dstType = NULL;
    int dstType=CV_32F;

    const char* keywords[] = { "src", "distanceType", "maskSize", "dst", "dstType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:distanceTransform", (char**)keywords, &pyobj_src, &pyobj_distanceType, &pyobj_maskSize, &pyobj_dst, &pyobj_dstType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_distanceType, distanceType, ArgInfo("distanceType", 0)) &&
        pyopencv_to(pyobj_maskSize, maskSize, ArgInfo("maskSize", 0)) &&
        pyopencv_to(pyobj_dstType, dstType, ArgInfo("dstType", 0)) )
    {
        ERRWRAP2(cv::distanceTransform(src, dst, distanceType, maskSize, dstType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_distanceType = NULL;
    int distanceType=0;
    PyObject* pyobj_maskSize = NULL;
    int maskSize=0;
    PyObject* pyobj_dstType = NULL;
    int dstType=CV_32F;

    const char* keywords[] = { "src", "distanceType", "maskSize", "dst", "dstType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:distanceTransform", (char**)keywords, &pyobj_src, &pyobj_distanceType, &pyobj_maskSize, &pyobj_dst, &pyobj_dstType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_distanceType, distanceType, ArgInfo("distanceType", 0)) &&
        pyopencv_to(pyobj_maskSize, maskSize, ArgInfo("maskSize", 0)) &&
        pyopencv_to(pyobj_dstType, dstType, ArgInfo("dstType", 0)) )
    {
        ERRWRAP2(cv::distanceTransform(src, dst, distanceType, maskSize, dstType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_distanceTransformWithLabels(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_distanceType = NULL;
    int distanceType=0;
    PyObject* pyobj_maskSize = NULL;
    int maskSize=0;
    PyObject* pyobj_labelType = NULL;
    int labelType=DIST_LABEL_CCOMP;

    const char* keywords[] = { "src", "distanceType", "maskSize", "dst", "labels", "labelType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:distanceTransformWithLabels", (char**)keywords, &pyobj_src, &pyobj_distanceType, &pyobj_maskSize, &pyobj_dst, &pyobj_labels, &pyobj_labelType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to(pyobj_distanceType, distanceType, ArgInfo("distanceType", 0)) &&
        pyopencv_to(pyobj_maskSize, maskSize, ArgInfo("maskSize", 0)) &&
        pyopencv_to(pyobj_labelType, labelType, ArgInfo("labelType", 0)) )
    {
        ERRWRAP2(cv::distanceTransform(src, dst, labels, distanceType, maskSize, labelType));
        return Py_BuildValue("(NN)", pyopencv_from(dst), pyopencv_from(labels));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_distanceType = NULL;
    int distanceType=0;
    PyObject* pyobj_maskSize = NULL;
    int maskSize=0;
    PyObject* pyobj_labelType = NULL;
    int labelType=DIST_LABEL_CCOMP;

    const char* keywords[] = { "src", "distanceType", "maskSize", "dst", "labels", "labelType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:distanceTransformWithLabels", (char**)keywords, &pyobj_src, &pyobj_distanceType, &pyobj_maskSize, &pyobj_dst, &pyobj_labels, &pyobj_labelType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to(pyobj_distanceType, distanceType, ArgInfo("distanceType", 0)) &&
        pyopencv_to(pyobj_maskSize, maskSize, ArgInfo("maskSize", 0)) &&
        pyopencv_to(pyobj_labelType, labelType, ArgInfo("labelType", 0)) )
    {
        ERRWRAP2(cv::distanceTransform(src, dst, labels, distanceType, maskSize, labelType));
        return Py_BuildValue("(NN)", pyopencv_from(dst), pyopencv_from(labels));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_divide(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:divide", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::divide(src1, src2, dst, scale, dtype));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:divide", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::divide(src1, src2, dst, scale, dtype));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_scale = NULL;
    double scale=0;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "scale", "src2", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:divide", (char**)keywords, &pyobj_scale, &pyobj_src2, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::divide(scale, src2, dst, dtype));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_scale = NULL;
    double scale=0;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "scale", "src2", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:divide", (char**)keywords, &pyobj_scale, &pyobj_src2, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::divide(scale, src2, dst, dtype));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_drawChessboardCorners(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_patternWasFound = NULL;
    bool patternWasFound=0;

    const char* keywords[] = { "image", "patternSize", "corners", "patternWasFound", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO:drawChessboardCorners", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_corners, &pyobj_patternWasFound) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 0)) &&
        pyopencv_to(pyobj_patternWasFound, patternWasFound, ArgInfo("patternWasFound", 0)) )
    {
        ERRWRAP2(cv::drawChessboardCorners(image, patternSize, corners, patternWasFound));
        return pyopencv_from(image);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_patternWasFound = NULL;
    bool patternWasFound=0;

    const char* keywords[] = { "image", "patternSize", "corners", "patternWasFound", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO:drawChessboardCorners", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_corners, &pyobj_patternWasFound) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 0)) &&
        pyopencv_to(pyobj_patternWasFound, patternWasFound, ArgInfo("patternWasFound", 0)) )
    {
        ERRWRAP2(cv::drawChessboardCorners(image, patternSize, corners, patternWasFound));
        return pyopencv_from(image);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_drawContours(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_contours = NULL;
    vector_Mat contours;
    PyObject* pyobj_contourIdx = NULL;
    int contourIdx=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_hierarchy = NULL;
    Mat hierarchy;
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=INT_MAX;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "image", "contours", "contourIdx", "color", "thickness", "lineType", "hierarchy", "maxLevel", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:drawContours", (char**)keywords, &pyobj_image, &pyobj_contours, &pyobj_contourIdx, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_hierarchy, &pyobj_maxLevel, &pyobj_offset) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to(pyobj_contours, contours, ArgInfo("contours", 0)) &&
        pyopencv_to(pyobj_contourIdx, contourIdx, ArgInfo("contourIdx", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_hierarchy, hierarchy, ArgInfo("hierarchy", 0)) &&
        pyopencv_to(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::drawContours(image, contours, contourIdx, color, thickness, lineType, hierarchy, maxLevel, offset));
        return pyopencv_from(image);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_contours = NULL;
    vector_UMat contours;
    PyObject* pyobj_contourIdx = NULL;
    int contourIdx=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_hierarchy = NULL;
    UMat hierarchy;
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=INT_MAX;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "image", "contours", "contourIdx", "color", "thickness", "lineType", "hierarchy", "maxLevel", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:drawContours", (char**)keywords, &pyobj_image, &pyobj_contours, &pyobj_contourIdx, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_hierarchy, &pyobj_maxLevel, &pyobj_offset) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to(pyobj_contours, contours, ArgInfo("contours", 0)) &&
        pyopencv_to(pyobj_contourIdx, contourIdx, ArgInfo("contourIdx", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_hierarchy, hierarchy, ArgInfo("hierarchy", 0)) &&
        pyopencv_to(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::drawContours(image, contours, contourIdx, color, thickness, lineType, hierarchy, maxLevel, offset));
        return pyopencv_from(image);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_drawFrameAxes(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvec = NULL;
    Mat rvec;
    PyObject* pyobj_tvec = NULL;
    Mat tvec;
    PyObject* pyobj_length = NULL;
    float length=0.f;
    PyObject* pyobj_thickness = NULL;
    int thickness=3;

    const char* keywords[] = { "image", "cameraMatrix", "distCoeffs", "rvec", "tvec", "length", "thickness", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:drawFrameAxes", (char**)keywords, &pyobj_image, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvec, &pyobj_tvec, &pyobj_length, &pyobj_thickness) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 0)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 0)) &&
        pyopencv_to(pyobj_length, length, ArgInfo("length", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) )
    {
        ERRWRAP2(cv::drawFrameAxes(image, cameraMatrix, distCoeffs, rvec, tvec, length, thickness));
        return pyopencv_from(image);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvec = NULL;
    UMat rvec;
    PyObject* pyobj_tvec = NULL;
    UMat tvec;
    PyObject* pyobj_length = NULL;
    float length=0.f;
    PyObject* pyobj_thickness = NULL;
    int thickness=3;

    const char* keywords[] = { "image", "cameraMatrix", "distCoeffs", "rvec", "tvec", "length", "thickness", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:drawFrameAxes", (char**)keywords, &pyobj_image, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvec, &pyobj_tvec, &pyobj_length, &pyobj_thickness) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 0)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 0)) &&
        pyopencv_to(pyobj_length, length, ArgInfo("length", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) )
    {
        ERRWRAP2(cv::drawFrameAxes(image, cameraMatrix, distCoeffs, rvec, tvec, length, thickness));
        return pyopencv_from(image);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_drawKeypoints(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_keypoints = NULL;
    vector_KeyPoint keypoints;
    PyObject* pyobj_outImage = NULL;
    Mat outImage;
    PyObject* pyobj_color = NULL;
    Scalar color=Scalar::all(-1);
    PyObject* pyobj_flags = NULL;
    DrawMatchesFlags flags=DrawMatchesFlags::DEFAULT;

    const char* keywords[] = { "image", "keypoints", "outImage", "color", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:drawKeypoints", (char**)keywords, &pyobj_image, &pyobj_keypoints, &pyobj_outImage, &pyobj_color, &pyobj_flags) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_keypoints, keypoints, ArgInfo("keypoints", 0)) &&
        pyopencv_to(pyobj_outImage, outImage, ArgInfo("outImage", 1)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::drawKeypoints(image, keypoints, outImage, color, flags));
        return pyopencv_from(outImage);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_keypoints = NULL;
    vector_KeyPoint keypoints;
    PyObject* pyobj_outImage = NULL;
    UMat outImage;
    PyObject* pyobj_color = NULL;
    Scalar color=Scalar::all(-1);
    PyObject* pyobj_flags = NULL;
    DrawMatchesFlags flags=DrawMatchesFlags::DEFAULT;

    const char* keywords[] = { "image", "keypoints", "outImage", "color", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:drawKeypoints", (char**)keywords, &pyobj_image, &pyobj_keypoints, &pyobj_outImage, &pyobj_color, &pyobj_flags) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_keypoints, keypoints, ArgInfo("keypoints", 0)) &&
        pyopencv_to(pyobj_outImage, outImage, ArgInfo("outImage", 1)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::drawKeypoints(image, keypoints, outImage, color, flags));
        return pyopencv_from(outImage);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_drawMarker(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_position = NULL;
    Point position;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_markerType = NULL;
    int markerType=MARKER_CROSS;
    PyObject* pyobj_markerSize = NULL;
    int markerSize=20;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_line_type = NULL;
    int line_type=8;

    const char* keywords[] = { "img", "position", "color", "markerType", "markerSize", "thickness", "line_type", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:drawMarker", (char**)keywords, &pyobj_img, &pyobj_position, &pyobj_color, &pyobj_markerType, &pyobj_markerSize, &pyobj_thickness, &pyobj_line_type) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_position, position, ArgInfo("position", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_markerType, markerType, ArgInfo("markerType", 0)) &&
        pyopencv_to(pyobj_markerSize, markerSize, ArgInfo("markerSize", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_line_type, line_type, ArgInfo("line_type", 0)) )
    {
        ERRWRAP2(cv::drawMarker(img, position, color, markerType, markerSize, thickness, line_type));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_position = NULL;
    Point position;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_markerType = NULL;
    int markerType=MARKER_CROSS;
    PyObject* pyobj_markerSize = NULL;
    int markerSize=20;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_line_type = NULL;
    int line_type=8;

    const char* keywords[] = { "img", "position", "color", "markerType", "markerSize", "thickness", "line_type", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:drawMarker", (char**)keywords, &pyobj_img, &pyobj_position, &pyobj_color, &pyobj_markerType, &pyobj_markerSize, &pyobj_thickness, &pyobj_line_type) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_position, position, ArgInfo("position", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_markerType, markerType, ArgInfo("markerType", 0)) &&
        pyopencv_to(pyobj_markerSize, markerSize, ArgInfo("markerSize", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_line_type, line_type, ArgInfo("line_type", 0)) )
    {
        ERRWRAP2(cv::drawMarker(img, position, color, markerType, markerSize, thickness, line_type));
        return pyopencv_from(img);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_drawMatches(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img1 = NULL;
    Mat img1;
    PyObject* pyobj_keypoints1 = NULL;
    vector_KeyPoint keypoints1;
    PyObject* pyobj_img2 = NULL;
    Mat img2;
    PyObject* pyobj_keypoints2 = NULL;
    vector_KeyPoint keypoints2;
    PyObject* pyobj_matches1to2 = NULL;
    vector_DMatch matches1to2;
    PyObject* pyobj_outImg = NULL;
    Mat outImg;
    PyObject* pyobj_matchColor = NULL;
    Scalar matchColor=Scalar::all(-1);
    PyObject* pyobj_singlePointColor = NULL;
    Scalar singlePointColor=Scalar::all(-1);
    PyObject* pyobj_matchesMask = NULL;
    vector_char matchesMask=std::vector<char>();
    PyObject* pyobj_flags = NULL;
    DrawMatchesFlags flags=DrawMatchesFlags::DEFAULT;

    const char* keywords[] = { "img1", "keypoints1", "img2", "keypoints2", "matches1to2", "outImg", "matchColor", "singlePointColor", "matchesMask", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OOOO:drawMatches", (char**)keywords, &pyobj_img1, &pyobj_keypoints1, &pyobj_img2, &pyobj_keypoints2, &pyobj_matches1to2, &pyobj_outImg, &pyobj_matchColor, &pyobj_singlePointColor, &pyobj_matchesMask, &pyobj_flags) &&
        pyopencv_to(pyobj_img1, img1, ArgInfo("img1", 0)) &&
        pyopencv_to(pyobj_keypoints1, keypoints1, ArgInfo("keypoints1", 0)) &&
        pyopencv_to(pyobj_img2, img2, ArgInfo("img2", 0)) &&
        pyopencv_to(pyobj_keypoints2, keypoints2, ArgInfo("keypoints2", 0)) &&
        pyopencv_to(pyobj_matches1to2, matches1to2, ArgInfo("matches1to2", 0)) &&
        pyopencv_to(pyobj_outImg, outImg, ArgInfo("outImg", 1)) &&
        pyopencv_to(pyobj_matchColor, matchColor, ArgInfo("matchColor", 0)) &&
        pyopencv_to(pyobj_singlePointColor, singlePointColor, ArgInfo("singlePointColor", 0)) &&
        pyopencv_to(pyobj_matchesMask, matchesMask, ArgInfo("matchesMask", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::drawMatches(img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor, matchesMask, flags));
        return pyopencv_from(outImg);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img1 = NULL;
    UMat img1;
    PyObject* pyobj_keypoints1 = NULL;
    vector_KeyPoint keypoints1;
    PyObject* pyobj_img2 = NULL;
    UMat img2;
    PyObject* pyobj_keypoints2 = NULL;
    vector_KeyPoint keypoints2;
    PyObject* pyobj_matches1to2 = NULL;
    vector_DMatch matches1to2;
    PyObject* pyobj_outImg = NULL;
    UMat outImg;
    PyObject* pyobj_matchColor = NULL;
    Scalar matchColor=Scalar::all(-1);
    PyObject* pyobj_singlePointColor = NULL;
    Scalar singlePointColor=Scalar::all(-1);
    PyObject* pyobj_matchesMask = NULL;
    vector_char matchesMask=std::vector<char>();
    PyObject* pyobj_flags = NULL;
    DrawMatchesFlags flags=DrawMatchesFlags::DEFAULT;

    const char* keywords[] = { "img1", "keypoints1", "img2", "keypoints2", "matches1to2", "outImg", "matchColor", "singlePointColor", "matchesMask", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OOOO:drawMatches", (char**)keywords, &pyobj_img1, &pyobj_keypoints1, &pyobj_img2, &pyobj_keypoints2, &pyobj_matches1to2, &pyobj_outImg, &pyobj_matchColor, &pyobj_singlePointColor, &pyobj_matchesMask, &pyobj_flags) &&
        pyopencv_to(pyobj_img1, img1, ArgInfo("img1", 0)) &&
        pyopencv_to(pyobj_keypoints1, keypoints1, ArgInfo("keypoints1", 0)) &&
        pyopencv_to(pyobj_img2, img2, ArgInfo("img2", 0)) &&
        pyopencv_to(pyobj_keypoints2, keypoints2, ArgInfo("keypoints2", 0)) &&
        pyopencv_to(pyobj_matches1to2, matches1to2, ArgInfo("matches1to2", 0)) &&
        pyopencv_to(pyobj_outImg, outImg, ArgInfo("outImg", 1)) &&
        pyopencv_to(pyobj_matchColor, matchColor, ArgInfo("matchColor", 0)) &&
        pyopencv_to(pyobj_singlePointColor, singlePointColor, ArgInfo("singlePointColor", 0)) &&
        pyopencv_to(pyobj_matchesMask, matchesMask, ArgInfo("matchesMask", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::drawMatches(img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor, matchesMask, flags));
        return pyopencv_from(outImg);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_drawMatchesKnn(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img1 = NULL;
    Mat img1;
    PyObject* pyobj_keypoints1 = NULL;
    vector_KeyPoint keypoints1;
    PyObject* pyobj_img2 = NULL;
    Mat img2;
    PyObject* pyobj_keypoints2 = NULL;
    vector_KeyPoint keypoints2;
    PyObject* pyobj_matches1to2 = NULL;
    vector_vector_DMatch matches1to2;
    PyObject* pyobj_outImg = NULL;
    Mat outImg;
    PyObject* pyobj_matchColor = NULL;
    Scalar matchColor=Scalar::all(-1);
    PyObject* pyobj_singlePointColor = NULL;
    Scalar singlePointColor=Scalar::all(-1);
    PyObject* pyobj_matchesMask = NULL;
    vector_vector_char matchesMask=std::vector<std::vector<char> >();
    PyObject* pyobj_flags = NULL;
    DrawMatchesFlags flags=DrawMatchesFlags::DEFAULT;

    const char* keywords[] = { "img1", "keypoints1", "img2", "keypoints2", "matches1to2", "outImg", "matchColor", "singlePointColor", "matchesMask", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OOOO:drawMatchesKnn", (char**)keywords, &pyobj_img1, &pyobj_keypoints1, &pyobj_img2, &pyobj_keypoints2, &pyobj_matches1to2, &pyobj_outImg, &pyobj_matchColor, &pyobj_singlePointColor, &pyobj_matchesMask, &pyobj_flags) &&
        pyopencv_to(pyobj_img1, img1, ArgInfo("img1", 0)) &&
        pyopencv_to(pyobj_keypoints1, keypoints1, ArgInfo("keypoints1", 0)) &&
        pyopencv_to(pyobj_img2, img2, ArgInfo("img2", 0)) &&
        pyopencv_to(pyobj_keypoints2, keypoints2, ArgInfo("keypoints2", 0)) &&
        pyopencv_to(pyobj_matches1to2, matches1to2, ArgInfo("matches1to2", 0)) &&
        pyopencv_to(pyobj_outImg, outImg, ArgInfo("outImg", 1)) &&
        pyopencv_to(pyobj_matchColor, matchColor, ArgInfo("matchColor", 0)) &&
        pyopencv_to(pyobj_singlePointColor, singlePointColor, ArgInfo("singlePointColor", 0)) &&
        pyopencv_to(pyobj_matchesMask, matchesMask, ArgInfo("matchesMask", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::drawMatches(img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor, matchesMask, flags));
        return pyopencv_from(outImg);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img1 = NULL;
    UMat img1;
    PyObject* pyobj_keypoints1 = NULL;
    vector_KeyPoint keypoints1;
    PyObject* pyobj_img2 = NULL;
    UMat img2;
    PyObject* pyobj_keypoints2 = NULL;
    vector_KeyPoint keypoints2;
    PyObject* pyobj_matches1to2 = NULL;
    vector_vector_DMatch matches1to2;
    PyObject* pyobj_outImg = NULL;
    UMat outImg;
    PyObject* pyobj_matchColor = NULL;
    Scalar matchColor=Scalar::all(-1);
    PyObject* pyobj_singlePointColor = NULL;
    Scalar singlePointColor=Scalar::all(-1);
    PyObject* pyobj_matchesMask = NULL;
    vector_vector_char matchesMask=std::vector<std::vector<char> >();
    PyObject* pyobj_flags = NULL;
    DrawMatchesFlags flags=DrawMatchesFlags::DEFAULT;

    const char* keywords[] = { "img1", "keypoints1", "img2", "keypoints2", "matches1to2", "outImg", "matchColor", "singlePointColor", "matchesMask", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OOOO:drawMatchesKnn", (char**)keywords, &pyobj_img1, &pyobj_keypoints1, &pyobj_img2, &pyobj_keypoints2, &pyobj_matches1to2, &pyobj_outImg, &pyobj_matchColor, &pyobj_singlePointColor, &pyobj_matchesMask, &pyobj_flags) &&
        pyopencv_to(pyobj_img1, img1, ArgInfo("img1", 0)) &&
        pyopencv_to(pyobj_keypoints1, keypoints1, ArgInfo("keypoints1", 0)) &&
        pyopencv_to(pyobj_img2, img2, ArgInfo("img2", 0)) &&
        pyopencv_to(pyobj_keypoints2, keypoints2, ArgInfo("keypoints2", 0)) &&
        pyopencv_to(pyobj_matches1to2, matches1to2, ArgInfo("matches1to2", 0)) &&
        pyopencv_to(pyobj_outImg, outImg, ArgInfo("outImg", 1)) &&
        pyopencv_to(pyobj_matchColor, matchColor, ArgInfo("matchColor", 0)) &&
        pyopencv_to(pyobj_singlePointColor, singlePointColor, ArgInfo("singlePointColor", 0)) &&
        pyopencv_to(pyobj_matchesMask, matchesMask, ArgInfo("matchesMask", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::drawMatches(img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor, matchesMask, flags));
        return pyopencv_from(outImg);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_edgePreservingFilter(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=1;
    PyObject* pyobj_sigma_s = NULL;
    float sigma_s=60;
    PyObject* pyobj_sigma_r = NULL;
    float sigma_r=0.4f;

    const char* keywords[] = { "src", "dst", "flags", "sigma_s", "sigma_r", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:edgePreservingFilter", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags, &pyobj_sigma_s, &pyobj_sigma_r) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_sigma_s, sigma_s, ArgInfo("sigma_s", 0)) &&
        pyopencv_to(pyobj_sigma_r, sigma_r, ArgInfo("sigma_r", 0)) )
    {
        ERRWRAP2(cv::edgePreservingFilter(src, dst, flags, sigma_s, sigma_r));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=1;
    PyObject* pyobj_sigma_s = NULL;
    float sigma_s=60;
    PyObject* pyobj_sigma_r = NULL;
    float sigma_r=0.4f;

    const char* keywords[] = { "src", "dst", "flags", "sigma_s", "sigma_r", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:edgePreservingFilter", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags, &pyobj_sigma_s, &pyobj_sigma_r) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_sigma_s, sigma_s, ArgInfo("sigma_s", 0)) &&
        pyopencv_to(pyobj_sigma_r, sigma_r, ArgInfo("sigma_r", 0)) )
    {
        ERRWRAP2(cv::edgePreservingFilter(src, dst, flags, sigma_s, sigma_r));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_eigen(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_eigenvalues = NULL;
    Mat eigenvalues;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    bool retval;

    const char* keywords[] = { "src", "eigenvalues", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:eigen", (char**)keywords, &pyobj_src, &pyobj_eigenvalues, &pyobj_eigenvectors) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) )
    {
        ERRWRAP2(retval = cv::eigen(src, eigenvalues, eigenvectors));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(eigenvalues), pyopencv_from(eigenvectors));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_eigenvalues = NULL;
    UMat eigenvalues;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    bool retval;

    const char* keywords[] = { "src", "eigenvalues", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:eigen", (char**)keywords, &pyobj_src, &pyobj_eigenvalues, &pyobj_eigenvectors) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) )
    {
        ERRWRAP2(retval = cv::eigen(src, eigenvalues, eigenvectors));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(eigenvalues), pyopencv_from(eigenvectors));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_eigenNonSymmetric(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_eigenvalues = NULL;
    Mat eigenvalues;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;

    const char* keywords[] = { "src", "eigenvalues", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:eigenNonSymmetric", (char**)keywords, &pyobj_src, &pyobj_eigenvalues, &pyobj_eigenvectors) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) )
    {
        ERRWRAP2(cv::eigenNonSymmetric(src, eigenvalues, eigenvectors));
        return Py_BuildValue("(NN)", pyopencv_from(eigenvalues), pyopencv_from(eigenvectors));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_eigenvalues = NULL;
    UMat eigenvalues;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;

    const char* keywords[] = { "src", "eigenvalues", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:eigenNonSymmetric", (char**)keywords, &pyobj_src, &pyobj_eigenvalues, &pyobj_eigenvectors) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) )
    {
        ERRWRAP2(cv::eigenNonSymmetric(src, eigenvalues, eigenvectors));
        return Py_BuildValue("(NN)", pyopencv_from(eigenvalues), pyopencv_from(eigenvectors));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_ellipse(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_center = NULL;
    Point center;
    PyObject* pyobj_axes = NULL;
    Size axes;
    PyObject* pyobj_angle = NULL;
    double angle=0;
    PyObject* pyobj_startAngle = NULL;
    double startAngle=0;
    PyObject* pyobj_endAngle = NULL;
    double endAngle=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "center", "axes", "angle", "startAngle", "endAngle", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOO|OOO:ellipse", (char**)keywords, &pyobj_img, &pyobj_center, &pyobj_axes, &pyobj_angle, &pyobj_startAngle, &pyobj_endAngle, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_axes, axes, ArgInfo("axes", 0)) &&
        pyopencv_to(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to(pyobj_startAngle, startAngle, ArgInfo("startAngle", 0)) &&
        pyopencv_to(pyobj_endAngle, endAngle, ArgInfo("endAngle", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::ellipse(img, center, axes, angle, startAngle, endAngle, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_center = NULL;
    Point center;
    PyObject* pyobj_axes = NULL;
    Size axes;
    PyObject* pyobj_angle = NULL;
    double angle=0;
    PyObject* pyobj_startAngle = NULL;
    double startAngle=0;
    PyObject* pyobj_endAngle = NULL;
    double endAngle=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "center", "axes", "angle", "startAngle", "endAngle", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOO|OOO:ellipse", (char**)keywords, &pyobj_img, &pyobj_center, &pyobj_axes, &pyobj_angle, &pyobj_startAngle, &pyobj_endAngle, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_axes, axes, ArgInfo("axes", 0)) &&
        pyopencv_to(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to(pyobj_startAngle, startAngle, ArgInfo("startAngle", 0)) &&
        pyopencv_to(pyobj_endAngle, endAngle, ArgInfo("endAngle", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::ellipse(img, center, axes, angle, startAngle, endAngle, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_box = NULL;
    RotatedRect box;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;

    const char* keywords[] = { "img", "box", "color", "thickness", "lineType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:ellipse", (char**)keywords, &pyobj_img, &pyobj_box, &pyobj_color, &pyobj_thickness, &pyobj_lineType) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_box, box, ArgInfo("box", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) )
    {
        ERRWRAP2(cv::ellipse(img, box, color, thickness, lineType));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_box = NULL;
    RotatedRect box;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;

    const char* keywords[] = { "img", "box", "color", "thickness", "lineType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:ellipse", (char**)keywords, &pyobj_img, &pyobj_box, &pyobj_color, &pyobj_thickness, &pyobj_lineType) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_box, box, ArgInfo("box", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) )
    {
        ERRWRAP2(cv::ellipse(img, box, color, thickness, lineType));
        return pyopencv_from(img);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_ellipse2Poly(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_center = NULL;
    Point center;
    PyObject* pyobj_axes = NULL;
    Size axes;
    PyObject* pyobj_angle = NULL;
    int angle=0;
    PyObject* pyobj_arcStart = NULL;
    int arcStart=0;
    PyObject* pyobj_arcEnd = NULL;
    int arcEnd=0;
    PyObject* pyobj_delta = NULL;
    int delta=0;
    vector_Point pts;

    const char* keywords[] = { "center", "axes", "angle", "arcStart", "arcEnd", "delta", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO:ellipse2Poly", (char**)keywords, &pyobj_center, &pyobj_axes, &pyobj_angle, &pyobj_arcStart, &pyobj_arcEnd, &pyobj_delta) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_axes, axes, ArgInfo("axes", 0)) &&
        pyopencv_to(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to(pyobj_arcStart, arcStart, ArgInfo("arcStart", 0)) &&
        pyopencv_to(pyobj_arcEnd, arcEnd, ArgInfo("arcEnd", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) )
    {
        ERRWRAP2(cv::ellipse2Poly(center, axes, angle, arcStart, arcEnd, delta, pts));
        return pyopencv_from(pts);
    }

    return NULL;
}

static PyObject* pyopencv_cv_equalizeHist(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:equalizeHist", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::equalizeHist(src, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:equalizeHist", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::equalizeHist(src, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_erode(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_kernel = NULL;
    Mat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOO:erode", (char**)keywords, &pyobj_src, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::erode(src, dst, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_kernel = NULL;
    UMat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOO:erode", (char**)keywords, &pyobj_src, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::erode(src, dst, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_estimateAffine2D(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_from = NULL;
    Mat from;
    PyObject* pyobj_to = NULL;
    Mat to;
    PyObject* pyobj_inliers = NULL;
    Mat inliers;
    PyObject* pyobj_method = NULL;
    int method=RANSAC;
    PyObject* pyobj_ransacReprojThreshold = NULL;
    double ransacReprojThreshold=3;
    PyObject* pyobj_maxIters = NULL;
    size_t maxIters=2000;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.99;
    PyObject* pyobj_refineIters = NULL;
    size_t refineIters=10;
    cv::Mat retval;

    const char* keywords[] = { "from", "to", "inliers", "method", "ransacReprojThreshold", "maxIters", "confidence", "refineIters", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOOO:estimateAffine2D", (char**)keywords, &pyobj_from, &pyobj_to, &pyobj_inliers, &pyobj_method, &pyobj_ransacReprojThreshold, &pyobj_maxIters, &pyobj_confidence, &pyobj_refineIters) &&
        pyopencv_to(pyobj_from, from, ArgInfo("from", 0)) &&
        pyopencv_to(pyobj_to, to, ArgInfo("to", 0)) &&
        pyopencv_to(pyobj_inliers, inliers, ArgInfo("inliers", 1)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_ransacReprojThreshold, ransacReprojThreshold, ArgInfo("ransacReprojThreshold", 0)) &&
        pyopencv_to(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) &&
        pyopencv_to(pyobj_refineIters, refineIters, ArgInfo("refineIters", 0)) )
    {
        ERRWRAP2(retval = cv::estimateAffine2D(from, to, inliers, method, ransacReprojThreshold, maxIters, confidence, refineIters));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(inliers));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_from = NULL;
    UMat from;
    PyObject* pyobj_to = NULL;
    UMat to;
    PyObject* pyobj_inliers = NULL;
    UMat inliers;
    PyObject* pyobj_method = NULL;
    int method=RANSAC;
    PyObject* pyobj_ransacReprojThreshold = NULL;
    double ransacReprojThreshold=3;
    PyObject* pyobj_maxIters = NULL;
    size_t maxIters=2000;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.99;
    PyObject* pyobj_refineIters = NULL;
    size_t refineIters=10;
    cv::Mat retval;

    const char* keywords[] = { "from", "to", "inliers", "method", "ransacReprojThreshold", "maxIters", "confidence", "refineIters", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOOO:estimateAffine2D", (char**)keywords, &pyobj_from, &pyobj_to, &pyobj_inliers, &pyobj_method, &pyobj_ransacReprojThreshold, &pyobj_maxIters, &pyobj_confidence, &pyobj_refineIters) &&
        pyopencv_to(pyobj_from, from, ArgInfo("from", 0)) &&
        pyopencv_to(pyobj_to, to, ArgInfo("to", 0)) &&
        pyopencv_to(pyobj_inliers, inliers, ArgInfo("inliers", 1)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_ransacReprojThreshold, ransacReprojThreshold, ArgInfo("ransacReprojThreshold", 0)) &&
        pyopencv_to(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) &&
        pyopencv_to(pyobj_refineIters, refineIters, ArgInfo("refineIters", 0)) )
    {
        ERRWRAP2(retval = cv::estimateAffine2D(from, to, inliers, method, ransacReprojThreshold, maxIters, confidence, refineIters));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(inliers));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_estimateAffine3D(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_out = NULL;
    Mat out;
    PyObject* pyobj_inliers = NULL;
    Mat inliers;
    PyObject* pyobj_ransacThreshold = NULL;
    double ransacThreshold=3;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.99;
    int retval;

    const char* keywords[] = { "src", "dst", "out", "inliers", "ransacThreshold", "confidence", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:estimateAffine3D", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_out, &pyobj_inliers, &pyobj_ransacThreshold, &pyobj_confidence) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 0)) &&
        pyopencv_to(pyobj_out, out, ArgInfo("out", 1)) &&
        pyopencv_to(pyobj_inliers, inliers, ArgInfo("inliers", 1)) &&
        pyopencv_to(pyobj_ransacThreshold, ransacThreshold, ArgInfo("ransacThreshold", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) )
    {
        ERRWRAP2(retval = cv::estimateAffine3D(src, dst, out, inliers, ransacThreshold, confidence));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(out), pyopencv_from(inliers));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_out = NULL;
    UMat out;
    PyObject* pyobj_inliers = NULL;
    UMat inliers;
    PyObject* pyobj_ransacThreshold = NULL;
    double ransacThreshold=3;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.99;
    int retval;

    const char* keywords[] = { "src", "dst", "out", "inliers", "ransacThreshold", "confidence", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:estimateAffine3D", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_out, &pyobj_inliers, &pyobj_ransacThreshold, &pyobj_confidence) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 0)) &&
        pyopencv_to(pyobj_out, out, ArgInfo("out", 1)) &&
        pyopencv_to(pyobj_inliers, inliers, ArgInfo("inliers", 1)) &&
        pyopencv_to(pyobj_ransacThreshold, ransacThreshold, ArgInfo("ransacThreshold", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) )
    {
        ERRWRAP2(retval = cv::estimateAffine3D(src, dst, out, inliers, ransacThreshold, confidence));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(out), pyopencv_from(inliers));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_estimateAffinePartial2D(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_from = NULL;
    Mat from;
    PyObject* pyobj_to = NULL;
    Mat to;
    PyObject* pyobj_inliers = NULL;
    Mat inliers;
    PyObject* pyobj_method = NULL;
    int method=RANSAC;
    PyObject* pyobj_ransacReprojThreshold = NULL;
    double ransacReprojThreshold=3;
    PyObject* pyobj_maxIters = NULL;
    size_t maxIters=2000;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.99;
    PyObject* pyobj_refineIters = NULL;
    size_t refineIters=10;
    cv::Mat retval;

    const char* keywords[] = { "from", "to", "inliers", "method", "ransacReprojThreshold", "maxIters", "confidence", "refineIters", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOOO:estimateAffinePartial2D", (char**)keywords, &pyobj_from, &pyobj_to, &pyobj_inliers, &pyobj_method, &pyobj_ransacReprojThreshold, &pyobj_maxIters, &pyobj_confidence, &pyobj_refineIters) &&
        pyopencv_to(pyobj_from, from, ArgInfo("from", 0)) &&
        pyopencv_to(pyobj_to, to, ArgInfo("to", 0)) &&
        pyopencv_to(pyobj_inliers, inliers, ArgInfo("inliers", 1)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_ransacReprojThreshold, ransacReprojThreshold, ArgInfo("ransacReprojThreshold", 0)) &&
        pyopencv_to(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) &&
        pyopencv_to(pyobj_refineIters, refineIters, ArgInfo("refineIters", 0)) )
    {
        ERRWRAP2(retval = cv::estimateAffinePartial2D(from, to, inliers, method, ransacReprojThreshold, maxIters, confidence, refineIters));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(inliers));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_from = NULL;
    UMat from;
    PyObject* pyobj_to = NULL;
    UMat to;
    PyObject* pyobj_inliers = NULL;
    UMat inliers;
    PyObject* pyobj_method = NULL;
    int method=RANSAC;
    PyObject* pyobj_ransacReprojThreshold = NULL;
    double ransacReprojThreshold=3;
    PyObject* pyobj_maxIters = NULL;
    size_t maxIters=2000;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.99;
    PyObject* pyobj_refineIters = NULL;
    size_t refineIters=10;
    cv::Mat retval;

    const char* keywords[] = { "from", "to", "inliers", "method", "ransacReprojThreshold", "maxIters", "confidence", "refineIters", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOOO:estimateAffinePartial2D", (char**)keywords, &pyobj_from, &pyobj_to, &pyobj_inliers, &pyobj_method, &pyobj_ransacReprojThreshold, &pyobj_maxIters, &pyobj_confidence, &pyobj_refineIters) &&
        pyopencv_to(pyobj_from, from, ArgInfo("from", 0)) &&
        pyopencv_to(pyobj_to, to, ArgInfo("to", 0)) &&
        pyopencv_to(pyobj_inliers, inliers, ArgInfo("inliers", 1)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_ransacReprojThreshold, ransacReprojThreshold, ArgInfo("ransacReprojThreshold", 0)) &&
        pyopencv_to(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) &&
        pyopencv_to(pyobj_refineIters, refineIters, ArgInfo("refineIters", 0)) )
    {
        ERRWRAP2(retval = cv::estimateAffinePartial2D(from, to, inliers, method, ransacReprojThreshold, maxIters, confidence, refineIters));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(inliers));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_estimateChessboardSharpness(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_rise_distance = NULL;
    float rise_distance=0.8F;
    PyObject* pyobj_vertical = NULL;
    bool vertical=false;
    PyObject* pyobj_sharpness = NULL;
    Mat sharpness;
    Scalar retval;

    const char* keywords[] = { "image", "patternSize", "corners", "rise_distance", "vertical", "sharpness", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:estimateChessboardSharpness", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_corners, &pyobj_rise_distance, &pyobj_vertical, &pyobj_sharpness) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 0)) &&
        pyopencv_to(pyobj_rise_distance, rise_distance, ArgInfo("rise_distance", 0)) &&
        pyopencv_to(pyobj_vertical, vertical, ArgInfo("vertical", 0)) &&
        pyopencv_to(pyobj_sharpness, sharpness, ArgInfo("sharpness", 1)) )
    {
        ERRWRAP2(retval = cv::estimateChessboardSharpness(image, patternSize, corners, rise_distance, vertical, sharpness));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(sharpness));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_rise_distance = NULL;
    float rise_distance=0.8F;
    PyObject* pyobj_vertical = NULL;
    bool vertical=false;
    PyObject* pyobj_sharpness = NULL;
    UMat sharpness;
    Scalar retval;

    const char* keywords[] = { "image", "patternSize", "corners", "rise_distance", "vertical", "sharpness", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:estimateChessboardSharpness", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_corners, &pyobj_rise_distance, &pyobj_vertical, &pyobj_sharpness) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 0)) &&
        pyopencv_to(pyobj_rise_distance, rise_distance, ArgInfo("rise_distance", 0)) &&
        pyopencv_to(pyobj_vertical, vertical, ArgInfo("vertical", 0)) &&
        pyopencv_to(pyobj_sharpness, sharpness, ArgInfo("sharpness", 1)) )
    {
        ERRWRAP2(retval = cv::estimateChessboardSharpness(image, patternSize, corners, rise_distance, vertical, sharpness));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(sharpness));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_exp(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:exp", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::exp(src, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:exp", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::exp(src, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_extractChannel(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_coi = NULL;
    int coi=0;

    const char* keywords[] = { "src", "coi", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:extractChannel", (char**)keywords, &pyobj_src, &pyobj_coi, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_coi, coi, ArgInfo("coi", 0)) )
    {
        ERRWRAP2(cv::extractChannel(src, dst, coi));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_coi = NULL;
    int coi=0;

    const char* keywords[] = { "src", "coi", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:extractChannel", (char**)keywords, &pyobj_src, &pyobj_coi, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_coi, coi, ArgInfo("coi", 0)) )
    {
        ERRWRAP2(cv::extractChannel(src, dst, coi));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fastAtan2(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_y = NULL;
    float y=0.f;
    PyObject* pyobj_x = NULL;
    float x=0.f;
    float retval;

    const char* keywords[] = { "y", "x", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:fastAtan2", (char**)keywords, &pyobj_y, &pyobj_x) &&
        pyopencv_to(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to(pyobj_x, x, ArgInfo("x", 0)) )
    {
        ERRWRAP2(retval = cv::fastAtan2(y, x));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_fastNlMeansDenoising(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_h = NULL;
    float h=3;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;

    const char* keywords[] = { "src", "dst", "h", "templateWindowSize", "searchWindowSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:fastNlMeansDenoising", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_h, &pyobj_templateWindowSize, &pyobj_searchWindowSize) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoising(src, dst, h, templateWindowSize, searchWindowSize));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_h = NULL;
    float h=3;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;

    const char* keywords[] = { "src", "dst", "h", "templateWindowSize", "searchWindowSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:fastNlMeansDenoising", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_h, &pyobj_templateWindowSize, &pyobj_searchWindowSize) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoising(src, dst, h, templateWindowSize, searchWindowSize));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_h = NULL;
    vector_float h;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;

    const char* keywords[] = { "src", "h", "dst", "templateWindowSize", "searchWindowSize", "normType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:fastNlMeansDenoising", (char**)keywords, &pyobj_src, &pyobj_h, &pyobj_dst, &pyobj_templateWindowSize, &pyobj_searchWindowSize, &pyobj_normType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoising(src, dst, h, templateWindowSize, searchWindowSize, normType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_h = NULL;
    vector_float h;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;

    const char* keywords[] = { "src", "h", "dst", "templateWindowSize", "searchWindowSize", "normType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:fastNlMeansDenoising", (char**)keywords, &pyobj_src, &pyobj_h, &pyobj_dst, &pyobj_templateWindowSize, &pyobj_searchWindowSize, &pyobj_normType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoising(src, dst, h, templateWindowSize, searchWindowSize, normType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fastNlMeansDenoisingColored(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_h = NULL;
    float h=3;
    PyObject* pyobj_hColor = NULL;
    float hColor=3;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;

    const char* keywords[] = { "src", "dst", "h", "hColor", "templateWindowSize", "searchWindowSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOO:fastNlMeansDenoisingColored", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_h, &pyobj_hColor, &pyobj_templateWindowSize, &pyobj_searchWindowSize) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_hColor, hColor, ArgInfo("hColor", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoisingColored(src, dst, h, hColor, templateWindowSize, searchWindowSize));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_h = NULL;
    float h=3;
    PyObject* pyobj_hColor = NULL;
    float hColor=3;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;

    const char* keywords[] = { "src", "dst", "h", "hColor", "templateWindowSize", "searchWindowSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOO:fastNlMeansDenoisingColored", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_h, &pyobj_hColor, &pyobj_templateWindowSize, &pyobj_searchWindowSize) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_hColor, hColor, ArgInfo("hColor", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoisingColored(src, dst, h, hColor, templateWindowSize, searchWindowSize));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fastNlMeansDenoisingColoredMulti(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_srcImgs = NULL;
    vector_Mat srcImgs;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_imgToDenoiseIndex = NULL;
    int imgToDenoiseIndex=0;
    PyObject* pyobj_temporalWindowSize = NULL;
    int temporalWindowSize=0;
    PyObject* pyobj_h = NULL;
    float h=3;
    PyObject* pyobj_hColor = NULL;
    float hColor=3;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;

    const char* keywords[] = { "srcImgs", "imgToDenoiseIndex", "temporalWindowSize", "dst", "h", "hColor", "templateWindowSize", "searchWindowSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOOO:fastNlMeansDenoisingColoredMulti", (char**)keywords, &pyobj_srcImgs, &pyobj_imgToDenoiseIndex, &pyobj_temporalWindowSize, &pyobj_dst, &pyobj_h, &pyobj_hColor, &pyobj_templateWindowSize, &pyobj_searchWindowSize) &&
        pyopencv_to(pyobj_srcImgs, srcImgs, ArgInfo("srcImgs", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_imgToDenoiseIndex, imgToDenoiseIndex, ArgInfo("imgToDenoiseIndex", 0)) &&
        pyopencv_to(pyobj_temporalWindowSize, temporalWindowSize, ArgInfo("temporalWindowSize", 0)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_hColor, hColor, ArgInfo("hColor", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoisingColoredMulti(srcImgs, dst, imgToDenoiseIndex, temporalWindowSize, h, hColor, templateWindowSize, searchWindowSize));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_srcImgs = NULL;
    vector_UMat srcImgs;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_imgToDenoiseIndex = NULL;
    int imgToDenoiseIndex=0;
    PyObject* pyobj_temporalWindowSize = NULL;
    int temporalWindowSize=0;
    PyObject* pyobj_h = NULL;
    float h=3;
    PyObject* pyobj_hColor = NULL;
    float hColor=3;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;

    const char* keywords[] = { "srcImgs", "imgToDenoiseIndex", "temporalWindowSize", "dst", "h", "hColor", "templateWindowSize", "searchWindowSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOOO:fastNlMeansDenoisingColoredMulti", (char**)keywords, &pyobj_srcImgs, &pyobj_imgToDenoiseIndex, &pyobj_temporalWindowSize, &pyobj_dst, &pyobj_h, &pyobj_hColor, &pyobj_templateWindowSize, &pyobj_searchWindowSize) &&
        pyopencv_to(pyobj_srcImgs, srcImgs, ArgInfo("srcImgs", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_imgToDenoiseIndex, imgToDenoiseIndex, ArgInfo("imgToDenoiseIndex", 0)) &&
        pyopencv_to(pyobj_temporalWindowSize, temporalWindowSize, ArgInfo("temporalWindowSize", 0)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_hColor, hColor, ArgInfo("hColor", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoisingColoredMulti(srcImgs, dst, imgToDenoiseIndex, temporalWindowSize, h, hColor, templateWindowSize, searchWindowSize));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fastNlMeansDenoisingMulti(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_srcImgs = NULL;
    vector_Mat srcImgs;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_imgToDenoiseIndex = NULL;
    int imgToDenoiseIndex=0;
    PyObject* pyobj_temporalWindowSize = NULL;
    int temporalWindowSize=0;
    PyObject* pyobj_h = NULL;
    float h=3;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;

    const char* keywords[] = { "srcImgs", "imgToDenoiseIndex", "temporalWindowSize", "dst", "h", "templateWindowSize", "searchWindowSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:fastNlMeansDenoisingMulti", (char**)keywords, &pyobj_srcImgs, &pyobj_imgToDenoiseIndex, &pyobj_temporalWindowSize, &pyobj_dst, &pyobj_h, &pyobj_templateWindowSize, &pyobj_searchWindowSize) &&
        pyopencv_to(pyobj_srcImgs, srcImgs, ArgInfo("srcImgs", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_imgToDenoiseIndex, imgToDenoiseIndex, ArgInfo("imgToDenoiseIndex", 0)) &&
        pyopencv_to(pyobj_temporalWindowSize, temporalWindowSize, ArgInfo("temporalWindowSize", 0)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoisingMulti(srcImgs, dst, imgToDenoiseIndex, temporalWindowSize, h, templateWindowSize, searchWindowSize));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_srcImgs = NULL;
    vector_UMat srcImgs;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_imgToDenoiseIndex = NULL;
    int imgToDenoiseIndex=0;
    PyObject* pyobj_temporalWindowSize = NULL;
    int temporalWindowSize=0;
    PyObject* pyobj_h = NULL;
    float h=3;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;

    const char* keywords[] = { "srcImgs", "imgToDenoiseIndex", "temporalWindowSize", "dst", "h", "templateWindowSize", "searchWindowSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:fastNlMeansDenoisingMulti", (char**)keywords, &pyobj_srcImgs, &pyobj_imgToDenoiseIndex, &pyobj_temporalWindowSize, &pyobj_dst, &pyobj_h, &pyobj_templateWindowSize, &pyobj_searchWindowSize) &&
        pyopencv_to(pyobj_srcImgs, srcImgs, ArgInfo("srcImgs", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_imgToDenoiseIndex, imgToDenoiseIndex, ArgInfo("imgToDenoiseIndex", 0)) &&
        pyopencv_to(pyobj_temporalWindowSize, temporalWindowSize, ArgInfo("temporalWindowSize", 0)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoisingMulti(srcImgs, dst, imgToDenoiseIndex, temporalWindowSize, h, templateWindowSize, searchWindowSize));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_srcImgs = NULL;
    vector_Mat srcImgs;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_imgToDenoiseIndex = NULL;
    int imgToDenoiseIndex=0;
    PyObject* pyobj_temporalWindowSize = NULL;
    int temporalWindowSize=0;
    PyObject* pyobj_h = NULL;
    vector_float h;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;

    const char* keywords[] = { "srcImgs", "imgToDenoiseIndex", "temporalWindowSize", "h", "dst", "templateWindowSize", "searchWindowSize", "normType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:fastNlMeansDenoisingMulti", (char**)keywords, &pyobj_srcImgs, &pyobj_imgToDenoiseIndex, &pyobj_temporalWindowSize, &pyobj_h, &pyobj_dst, &pyobj_templateWindowSize, &pyobj_searchWindowSize, &pyobj_normType) &&
        pyopencv_to(pyobj_srcImgs, srcImgs, ArgInfo("srcImgs", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_imgToDenoiseIndex, imgToDenoiseIndex, ArgInfo("imgToDenoiseIndex", 0)) &&
        pyopencv_to(pyobj_temporalWindowSize, temporalWindowSize, ArgInfo("temporalWindowSize", 0)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoisingMulti(srcImgs, dst, imgToDenoiseIndex, temporalWindowSize, h, templateWindowSize, searchWindowSize, normType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_srcImgs = NULL;
    vector_UMat srcImgs;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_imgToDenoiseIndex = NULL;
    int imgToDenoiseIndex=0;
    PyObject* pyobj_temporalWindowSize = NULL;
    int temporalWindowSize=0;
    PyObject* pyobj_h = NULL;
    vector_float h;
    PyObject* pyobj_templateWindowSize = NULL;
    int templateWindowSize=7;
    PyObject* pyobj_searchWindowSize = NULL;
    int searchWindowSize=21;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;

    const char* keywords[] = { "srcImgs", "imgToDenoiseIndex", "temporalWindowSize", "h", "dst", "templateWindowSize", "searchWindowSize", "normType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:fastNlMeansDenoisingMulti", (char**)keywords, &pyobj_srcImgs, &pyobj_imgToDenoiseIndex, &pyobj_temporalWindowSize, &pyobj_h, &pyobj_dst, &pyobj_templateWindowSize, &pyobj_searchWindowSize, &pyobj_normType) &&
        pyopencv_to(pyobj_srcImgs, srcImgs, ArgInfo("srcImgs", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_imgToDenoiseIndex, imgToDenoiseIndex, ArgInfo("imgToDenoiseIndex", 0)) &&
        pyopencv_to(pyobj_temporalWindowSize, temporalWindowSize, ArgInfo("temporalWindowSize", 0)) &&
        pyopencv_to(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to(pyobj_templateWindowSize, templateWindowSize, ArgInfo("templateWindowSize", 0)) &&
        pyopencv_to(pyobj_searchWindowSize, searchWindowSize, ArgInfo("searchWindowSize", 0)) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) )
    {
        ERRWRAP2(cv::fastNlMeansDenoisingMulti(srcImgs, dst, imgToDenoiseIndex, temporalWindowSize, h, templateWindowSize, searchWindowSize, normType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fillConvexPoly(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_points = NULL;
    Mat points;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "points", "color", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:fillConvexPoly", (char**)keywords, &pyobj_img, &pyobj_points, &pyobj_color, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::fillConvexPoly(img, points, color, lineType, shift));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_points = NULL;
    UMat points;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "points", "color", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:fillConvexPoly", (char**)keywords, &pyobj_img, &pyobj_points, &pyobj_color, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::fillConvexPoly(img, points, color, lineType, shift));
        return pyopencv_from(img);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fillPoly(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pts = NULL;
    vector_Mat pts;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "img", "pts", "color", "lineType", "shift", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:fillPoly", (char**)keywords, &pyobj_img, &pyobj_pts, &pyobj_color, &pyobj_lineType, &pyobj_shift, &pyobj_offset) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_pts, pts, ArgInfo("pts", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) &&
        pyopencv_to(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::fillPoly(img, pts, color, lineType, shift, offset));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pts = NULL;
    vector_UMat pts;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "img", "pts", "color", "lineType", "shift", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:fillPoly", (char**)keywords, &pyobj_img, &pyobj_pts, &pyobj_color, &pyobj_lineType, &pyobj_shift, &pyobj_offset) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_pts, pts, ArgInfo("pts", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) &&
        pyopencv_to(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::fillPoly(img, pts, color, lineType, shift, offset));
        return pyopencv_from(img);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_filter2D(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_kernel = NULL;
    Mat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "kernel", "dst", "anchor", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:filter2D", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::filter2D(src, dst, ddepth, kernel, anchor, delta, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_kernel = NULL;
    UMat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "kernel", "dst", "anchor", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:filter2D", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::filter2D(src, dst, ddepth, kernel, anchor, delta, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_filterHomographyDecompByVisibleRefpoints(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_rotations = NULL;
    vector_Mat rotations;
    PyObject* pyobj_normals = NULL;
    vector_Mat normals;
    PyObject* pyobj_beforePoints = NULL;
    Mat beforePoints;
    PyObject* pyobj_afterPoints = NULL;
    Mat afterPoints;
    PyObject* pyobj_possibleSolutions = NULL;
    Mat possibleSolutions;
    PyObject* pyobj_pointsMask = NULL;
    Mat pointsMask;

    const char* keywords[] = { "rotations", "normals", "beforePoints", "afterPoints", "possibleSolutions", "pointsMask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:filterHomographyDecompByVisibleRefpoints", (char**)keywords, &pyobj_rotations, &pyobj_normals, &pyobj_beforePoints, &pyobj_afterPoints, &pyobj_possibleSolutions, &pyobj_pointsMask) &&
        pyopencv_to(pyobj_rotations, rotations, ArgInfo("rotations", 0)) &&
        pyopencv_to(pyobj_normals, normals, ArgInfo("normals", 0)) &&
        pyopencv_to(pyobj_beforePoints, beforePoints, ArgInfo("beforePoints", 0)) &&
        pyopencv_to(pyobj_afterPoints, afterPoints, ArgInfo("afterPoints", 0)) &&
        pyopencv_to(pyobj_possibleSolutions, possibleSolutions, ArgInfo("possibleSolutions", 1)) &&
        pyopencv_to(pyobj_pointsMask, pointsMask, ArgInfo("pointsMask", 0)) )
    {
        ERRWRAP2(cv::filterHomographyDecompByVisibleRefpoints(rotations, normals, beforePoints, afterPoints, possibleSolutions, pointsMask));
        return pyopencv_from(possibleSolutions);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_rotations = NULL;
    vector_UMat rotations;
    PyObject* pyobj_normals = NULL;
    vector_UMat normals;
    PyObject* pyobj_beforePoints = NULL;
    UMat beforePoints;
    PyObject* pyobj_afterPoints = NULL;
    UMat afterPoints;
    PyObject* pyobj_possibleSolutions = NULL;
    UMat possibleSolutions;
    PyObject* pyobj_pointsMask = NULL;
    UMat pointsMask;

    const char* keywords[] = { "rotations", "normals", "beforePoints", "afterPoints", "possibleSolutions", "pointsMask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:filterHomographyDecompByVisibleRefpoints", (char**)keywords, &pyobj_rotations, &pyobj_normals, &pyobj_beforePoints, &pyobj_afterPoints, &pyobj_possibleSolutions, &pyobj_pointsMask) &&
        pyopencv_to(pyobj_rotations, rotations, ArgInfo("rotations", 0)) &&
        pyopencv_to(pyobj_normals, normals, ArgInfo("normals", 0)) &&
        pyopencv_to(pyobj_beforePoints, beforePoints, ArgInfo("beforePoints", 0)) &&
        pyopencv_to(pyobj_afterPoints, afterPoints, ArgInfo("afterPoints", 0)) &&
        pyopencv_to(pyobj_possibleSolutions, possibleSolutions, ArgInfo("possibleSolutions", 1)) &&
        pyopencv_to(pyobj_pointsMask, pointsMask, ArgInfo("pointsMask", 0)) )
    {
        ERRWRAP2(cv::filterHomographyDecompByVisibleRefpoints(rotations, normals, beforePoints, afterPoints, possibleSolutions, pointsMask));
        return pyopencv_from(possibleSolutions);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_filterSpeckles(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_newVal = NULL;
    double newVal=0;
    PyObject* pyobj_maxSpeckleSize = NULL;
    int maxSpeckleSize=0;
    PyObject* pyobj_maxDiff = NULL;
    double maxDiff=0;
    PyObject* pyobj_buf = NULL;
    Mat buf;

    const char* keywords[] = { "img", "newVal", "maxSpeckleSize", "maxDiff", "buf", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:filterSpeckles", (char**)keywords, &pyobj_img, &pyobj_newVal, &pyobj_maxSpeckleSize, &pyobj_maxDiff, &pyobj_buf) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_newVal, newVal, ArgInfo("newVal", 0)) &&
        pyopencv_to(pyobj_maxSpeckleSize, maxSpeckleSize, ArgInfo("maxSpeckleSize", 0)) &&
        pyopencv_to(pyobj_maxDiff, maxDiff, ArgInfo("maxDiff", 0)) &&
        pyopencv_to(pyobj_buf, buf, ArgInfo("buf", 1)) )
    {
        ERRWRAP2(cv::filterSpeckles(img, newVal, maxSpeckleSize, maxDiff, buf));
        return Py_BuildValue("(NN)", pyopencv_from(img), pyopencv_from(buf));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_newVal = NULL;
    double newVal=0;
    PyObject* pyobj_maxSpeckleSize = NULL;
    int maxSpeckleSize=0;
    PyObject* pyobj_maxDiff = NULL;
    double maxDiff=0;
    PyObject* pyobj_buf = NULL;
    UMat buf;

    const char* keywords[] = { "img", "newVal", "maxSpeckleSize", "maxDiff", "buf", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:filterSpeckles", (char**)keywords, &pyobj_img, &pyobj_newVal, &pyobj_maxSpeckleSize, &pyobj_maxDiff, &pyobj_buf) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_newVal, newVal, ArgInfo("newVal", 0)) &&
        pyopencv_to(pyobj_maxSpeckleSize, maxSpeckleSize, ArgInfo("maxSpeckleSize", 0)) &&
        pyopencv_to(pyobj_maxDiff, maxDiff, ArgInfo("maxDiff", 0)) &&
        pyopencv_to(pyobj_buf, buf, ArgInfo("buf", 1)) )
    {
        ERRWRAP2(cv::filterSpeckles(img, newVal, maxSpeckleSize, maxDiff, buf));
        return Py_BuildValue("(NN)", pyopencv_from(img), pyopencv_from(buf));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_find4QuadCornerSubpix(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_region_size = NULL;
    Size region_size;
    bool retval;

    const char* keywords[] = { "img", "corners", "region_size", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:find4QuadCornerSubpix", (char**)keywords, &pyobj_img, &pyobj_corners, &pyobj_region_size) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_region_size, region_size, ArgInfo("region_size", 0)) )
    {
        ERRWRAP2(retval = cv::find4QuadCornerSubpix(img, corners, region_size));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(corners));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_region_size = NULL;
    Size region_size;
    bool retval;

    const char* keywords[] = { "img", "corners", "region_size", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:find4QuadCornerSubpix", (char**)keywords, &pyobj_img, &pyobj_corners, &pyobj_region_size) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_region_size, region_size, ArgInfo("region_size", 0)) )
    {
        ERRWRAP2(retval = cv::find4QuadCornerSubpix(img, corners, region_size));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(corners));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_findChessboardCorners(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_flags = NULL;
    int flags=CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE;
    bool retval;

    const char* keywords[] = { "image", "patternSize", "corners", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:findChessboardCorners", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_corners, &pyobj_flags) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::findChessboardCorners(image, patternSize, corners, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(corners));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_flags = NULL;
    int flags=CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE;
    bool retval;

    const char* keywords[] = { "image", "patternSize", "corners", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:findChessboardCorners", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_corners, &pyobj_flags) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::findChessboardCorners(image, patternSize, corners, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(corners));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_findChessboardCornersSB(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    bool retval;

    const char* keywords[] = { "image", "patternSize", "corners", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:findChessboardCornersSB", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_corners, &pyobj_flags) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::findChessboardCornersSB(image, patternSize, corners, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(corners));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    bool retval;

    const char* keywords[] = { "image", "patternSize", "corners", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:findChessboardCornersSB", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_corners, &pyobj_flags) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::findChessboardCornersSB(image, patternSize, corners, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(corners));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_findChessboardCornersSBWithMeta(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_meta = NULL;
    Mat meta;
    bool retval;

    const char* keywords[] = { "image", "patternSize", "flags", "corners", "meta", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:findChessboardCornersSBWithMeta", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_flags, &pyobj_corners, &pyobj_meta) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_meta, meta, ArgInfo("meta", 1)) )
    {
        ERRWRAP2(retval = cv::findChessboardCornersSB(image, patternSize, corners, flags, meta));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(corners), pyopencv_from(meta));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_meta = NULL;
    UMat meta;
    bool retval;

    const char* keywords[] = { "image", "patternSize", "flags", "corners", "meta", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:findChessboardCornersSBWithMeta", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_flags, &pyobj_corners, &pyobj_meta) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_meta, meta, ArgInfo("meta", 1)) )
    {
        ERRWRAP2(retval = cv::findChessboardCornersSB(image, patternSize, corners, flags, meta));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(corners), pyopencv_from(meta));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_findCirclesGrid(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_centers = NULL;
    Mat centers;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_blobDetector = NULL;
    Ptr<FeatureDetector> blobDetector;
    PyObject* pyobj_parameters = NULL;
    CirclesGridFinderParameters parameters;
    bool retval;

    const char* keywords[] = { "image", "patternSize", "flags", "blobDetector", "parameters", "centers", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|O:findCirclesGrid", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_flags, &pyobj_blobDetector, &pyobj_parameters, &pyobj_centers) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_centers, centers, ArgInfo("centers", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_blobDetector, blobDetector, ArgInfo("blobDetector", 0)) &&
        pyopencv_to(pyobj_parameters, parameters, ArgInfo("parameters", 0)) )
    {
        ERRWRAP2(retval = cv::findCirclesGrid(image, patternSize, centers, flags, blobDetector, parameters));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(centers));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_centers = NULL;
    UMat centers;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_blobDetector = NULL;
    Ptr<FeatureDetector> blobDetector;
    PyObject* pyobj_parameters = NULL;
    CirclesGridFinderParameters parameters;
    bool retval;

    const char* keywords[] = { "image", "patternSize", "flags", "blobDetector", "parameters", "centers", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|O:findCirclesGrid", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_flags, &pyobj_blobDetector, &pyobj_parameters, &pyobj_centers) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_centers, centers, ArgInfo("centers", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_blobDetector, blobDetector, ArgInfo("blobDetector", 0)) &&
        pyopencv_to(pyobj_parameters, parameters, ArgInfo("parameters", 0)) )
    {
        ERRWRAP2(retval = cv::findCirclesGrid(image, patternSize, centers, flags, blobDetector, parameters));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(centers));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_centers = NULL;
    Mat centers;
    PyObject* pyobj_flags = NULL;
    int flags=CALIB_CB_SYMMETRIC_GRID;
    PyObject* pyobj_blobDetector = NULL;
    Ptr<FeatureDetector> blobDetector=SimpleBlobDetector::create();
    bool retval;

    const char* keywords[] = { "image", "patternSize", "centers", "flags", "blobDetector", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:findCirclesGrid", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_centers, &pyobj_flags, &pyobj_blobDetector) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_centers, centers, ArgInfo("centers", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_blobDetector, blobDetector, ArgInfo("blobDetector", 0)) )
    {
        ERRWRAP2(retval = cv::findCirclesGrid(image, patternSize, centers, flags, blobDetector));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(centers));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_patternSize = NULL;
    Size patternSize;
    PyObject* pyobj_centers = NULL;
    UMat centers;
    PyObject* pyobj_flags = NULL;
    int flags=CALIB_CB_SYMMETRIC_GRID;
    PyObject* pyobj_blobDetector = NULL;
    Ptr<FeatureDetector> blobDetector=SimpleBlobDetector::create();
    bool retval;

    const char* keywords[] = { "image", "patternSize", "centers", "flags", "blobDetector", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:findCirclesGrid", (char**)keywords, &pyobj_image, &pyobj_patternSize, &pyobj_centers, &pyobj_flags, &pyobj_blobDetector) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patternSize, patternSize, ArgInfo("patternSize", 0)) &&
        pyopencv_to(pyobj_centers, centers, ArgInfo("centers", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_blobDetector, blobDetector, ArgInfo("blobDetector", 0)) )
    {
        ERRWRAP2(retval = cv::findCirclesGrid(image, patternSize, centers, flags, blobDetector));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(centers));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_findContours(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_contours = NULL;
    vector_Mat contours;
    PyObject* pyobj_hierarchy = NULL;
    Mat hierarchy;
    PyObject* pyobj_mode = NULL;
    int mode=0;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "image", "mode", "method", "contours", "hierarchy", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:findContours", (char**)keywords, &pyobj_image, &pyobj_mode, &pyobj_method, &pyobj_contours, &pyobj_hierarchy, &pyobj_offset) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_contours, contours, ArgInfo("contours", 1)) &&
        pyopencv_to(pyobj_hierarchy, hierarchy, ArgInfo("hierarchy", 1)) &&
        pyopencv_to(pyobj_mode, mode, ArgInfo("mode", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::findContours(image, contours, hierarchy, mode, method, offset));
        return Py_BuildValue("(NN)", pyopencv_from(contours), pyopencv_from(hierarchy));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_contours = NULL;
    vector_UMat contours;
    PyObject* pyobj_hierarchy = NULL;
    UMat hierarchy;
    PyObject* pyobj_mode = NULL;
    int mode=0;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "image", "mode", "method", "contours", "hierarchy", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:findContours", (char**)keywords, &pyobj_image, &pyobj_mode, &pyobj_method, &pyobj_contours, &pyobj_hierarchy, &pyobj_offset) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_contours, contours, ArgInfo("contours", 1)) &&
        pyopencv_to(pyobj_hierarchy, hierarchy, ArgInfo("hierarchy", 1)) &&
        pyopencv_to(pyobj_mode, mode, ArgInfo("mode", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::findContours(image, contours, hierarchy, mode, method, offset));
        return Py_BuildValue("(NN)", pyopencv_from(contours), pyopencv_from(hierarchy));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_findEssentialMat(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points1 = NULL;
    Mat points1;
    PyObject* pyobj_points2 = NULL;
    Mat points2;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_method = NULL;
    int method=RANSAC;
    PyObject* pyobj_prob = NULL;
    double prob=0.999;
    PyObject* pyobj_threshold = NULL;
    double threshold=1.0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    Mat retval;

    const char* keywords[] = { "points1", "points2", "cameraMatrix", "method", "prob", "threshold", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:findEssentialMat", (char**)keywords, &pyobj_points1, &pyobj_points2, &pyobj_cameraMatrix, &pyobj_method, &pyobj_prob, &pyobj_threshold, &pyobj_mask) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_prob, prob, ArgInfo("prob", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::findEssentialMat(points1, points2, cameraMatrix, method, prob, threshold, mask));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points1 = NULL;
    UMat points1;
    PyObject* pyobj_points2 = NULL;
    UMat points2;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_method = NULL;
    int method=RANSAC;
    PyObject* pyobj_prob = NULL;
    double prob=0.999;
    PyObject* pyobj_threshold = NULL;
    double threshold=1.0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    Mat retval;

    const char* keywords[] = { "points1", "points2", "cameraMatrix", "method", "prob", "threshold", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:findEssentialMat", (char**)keywords, &pyobj_points1, &pyobj_points2, &pyobj_cameraMatrix, &pyobj_method, &pyobj_prob, &pyobj_threshold, &pyobj_mask) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_prob, prob, ArgInfo("prob", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::findEssentialMat(points1, points2, cameraMatrix, method, prob, threshold, mask));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points1 = NULL;
    Mat points1;
    PyObject* pyobj_points2 = NULL;
    Mat points2;
    PyObject* pyobj_focal = NULL;
    double focal=1.0;
    PyObject* pyobj_pp = NULL;
    Point2d pp=Point2d(0, 0);
    PyObject* pyobj_method = NULL;
    int method=RANSAC;
    PyObject* pyobj_prob = NULL;
    double prob=0.999;
    PyObject* pyobj_threshold = NULL;
    double threshold=1.0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    Mat retval;

    const char* keywords[] = { "points1", "points2", "focal", "pp", "method", "prob", "threshold", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOOO:findEssentialMat", (char**)keywords, &pyobj_points1, &pyobj_points2, &pyobj_focal, &pyobj_pp, &pyobj_method, &pyobj_prob, &pyobj_threshold, &pyobj_mask) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_focal, focal, ArgInfo("focal", 0)) &&
        pyopencv_to(pyobj_pp, pp, ArgInfo("pp", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_prob, prob, ArgInfo("prob", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::findEssentialMat(points1, points2, focal, pp, method, prob, threshold, mask));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points1 = NULL;
    UMat points1;
    PyObject* pyobj_points2 = NULL;
    UMat points2;
    PyObject* pyobj_focal = NULL;
    double focal=1.0;
    PyObject* pyobj_pp = NULL;
    Point2d pp=Point2d(0, 0);
    PyObject* pyobj_method = NULL;
    int method=RANSAC;
    PyObject* pyobj_prob = NULL;
    double prob=0.999;
    PyObject* pyobj_threshold = NULL;
    double threshold=1.0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    Mat retval;

    const char* keywords[] = { "points1", "points2", "focal", "pp", "method", "prob", "threshold", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOOO:findEssentialMat", (char**)keywords, &pyobj_points1, &pyobj_points2, &pyobj_focal, &pyobj_pp, &pyobj_method, &pyobj_prob, &pyobj_threshold, &pyobj_mask) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_focal, focal, ArgInfo("focal", 0)) &&
        pyopencv_to(pyobj_pp, pp, ArgInfo("pp", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_prob, prob, ArgInfo("prob", 0)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::findEssentialMat(points1, points2, focal, pp, method, prob, threshold, mask));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mask));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_findFundamentalMat(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points1 = NULL;
    Mat points1;
    PyObject* pyobj_points2 = NULL;
    Mat points2;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_ransacReprojThreshold = NULL;
    double ransacReprojThreshold=0;
    PyObject* pyobj_confidence = NULL;
    double confidence=0;
    PyObject* pyobj_maxIters = NULL;
    int maxIters=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    Mat retval;

    const char* keywords[] = { "points1", "points2", "method", "ransacReprojThreshold", "confidence", "maxIters", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:findFundamentalMat", (char**)keywords, &pyobj_points1, &pyobj_points2, &pyobj_method, &pyobj_ransacReprojThreshold, &pyobj_confidence, &pyobj_maxIters, &pyobj_mask) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_ransacReprojThreshold, ransacReprojThreshold, ArgInfo("ransacReprojThreshold", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) &&
        pyopencv_to(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::findFundamentalMat(points1, points2, method, ransacReprojThreshold, confidence, maxIters, mask));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points1 = NULL;
    UMat points1;
    PyObject* pyobj_points2 = NULL;
    UMat points2;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_ransacReprojThreshold = NULL;
    double ransacReprojThreshold=0;
    PyObject* pyobj_confidence = NULL;
    double confidence=0;
    PyObject* pyobj_maxIters = NULL;
    int maxIters=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    Mat retval;

    const char* keywords[] = { "points1", "points2", "method", "ransacReprojThreshold", "confidence", "maxIters", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:findFundamentalMat", (char**)keywords, &pyobj_points1, &pyobj_points2, &pyobj_method, &pyobj_ransacReprojThreshold, &pyobj_confidence, &pyobj_maxIters, &pyobj_mask) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_ransacReprojThreshold, ransacReprojThreshold, ArgInfo("ransacReprojThreshold", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) &&
        pyopencv_to(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::findFundamentalMat(points1, points2, method, ransacReprojThreshold, confidence, maxIters, mask));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points1 = NULL;
    Mat points1;
    PyObject* pyobj_points2 = NULL;
    Mat points2;
    PyObject* pyobj_method = NULL;
    int method=FM_RANSAC;
    PyObject* pyobj_ransacReprojThreshold = NULL;
    double ransacReprojThreshold=3.;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.99;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    Mat retval;

    const char* keywords[] = { "points1", "points2", "method", "ransacReprojThreshold", "confidence", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:findFundamentalMat", (char**)keywords, &pyobj_points1, &pyobj_points2, &pyobj_method, &pyobj_ransacReprojThreshold, &pyobj_confidence, &pyobj_mask) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_ransacReprojThreshold, ransacReprojThreshold, ArgInfo("ransacReprojThreshold", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::findFundamentalMat(points1, points2, method, ransacReprojThreshold, confidence, mask));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points1 = NULL;
    UMat points1;
    PyObject* pyobj_points2 = NULL;
    UMat points2;
    PyObject* pyobj_method = NULL;
    int method=FM_RANSAC;
    PyObject* pyobj_ransacReprojThreshold = NULL;
    double ransacReprojThreshold=3.;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.99;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    Mat retval;

    const char* keywords[] = { "points1", "points2", "method", "ransacReprojThreshold", "confidence", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:findFundamentalMat", (char**)keywords, &pyobj_points1, &pyobj_points2, &pyobj_method, &pyobj_ransacReprojThreshold, &pyobj_confidence, &pyobj_mask) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_ransacReprojThreshold, ransacReprojThreshold, ArgInfo("ransacReprojThreshold", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::findFundamentalMat(points1, points2, method, ransacReprojThreshold, confidence, mask));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mask));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_findHomography(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_srcPoints = NULL;
    Mat srcPoints;
    PyObject* pyobj_dstPoints = NULL;
    Mat dstPoints;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_ransacReprojThreshold = NULL;
    double ransacReprojThreshold=3;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_maxIters = NULL;
    int maxIters=2000;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.995;
    Mat retval;

    const char* keywords[] = { "srcPoints", "dstPoints", "method", "ransacReprojThreshold", "mask", "maxIters", "confidence", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOO:findHomography", (char**)keywords, &pyobj_srcPoints, &pyobj_dstPoints, &pyobj_method, &pyobj_ransacReprojThreshold, &pyobj_mask, &pyobj_maxIters, &pyobj_confidence) &&
        pyopencv_to(pyobj_srcPoints, srcPoints, ArgInfo("srcPoints", 0)) &&
        pyopencv_to(pyobj_dstPoints, dstPoints, ArgInfo("dstPoints", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_ransacReprojThreshold, ransacReprojThreshold, ArgInfo("ransacReprojThreshold", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) )
    {
        ERRWRAP2(retval = cv::findHomography(srcPoints, dstPoints, method, ransacReprojThreshold, mask, maxIters, confidence));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_srcPoints = NULL;
    UMat srcPoints;
    PyObject* pyobj_dstPoints = NULL;
    UMat dstPoints;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_ransacReprojThreshold = NULL;
    double ransacReprojThreshold=3;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_maxIters = NULL;
    int maxIters=2000;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.995;
    Mat retval;

    const char* keywords[] = { "srcPoints", "dstPoints", "method", "ransacReprojThreshold", "mask", "maxIters", "confidence", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOO:findHomography", (char**)keywords, &pyobj_srcPoints, &pyobj_dstPoints, &pyobj_method, &pyobj_ransacReprojThreshold, &pyobj_mask, &pyobj_maxIters, &pyobj_confidence) &&
        pyopencv_to(pyobj_srcPoints, srcPoints, ArgInfo("srcPoints", 0)) &&
        pyopencv_to(pyobj_dstPoints, dstPoints, ArgInfo("dstPoints", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_ransacReprojThreshold, ransacReprojThreshold, ArgInfo("ransacReprojThreshold", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) )
    {
        ERRWRAP2(retval = cv::findHomography(srcPoints, dstPoints, method, ransacReprojThreshold, mask, maxIters, confidence));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mask));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_findNonZero(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_idx = NULL;
    Mat idx;

    const char* keywords[] = { "src", "idx", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:findNonZero", (char**)keywords, &pyobj_src, &pyobj_idx) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_idx, idx, ArgInfo("idx", 1)) )
    {
        ERRWRAP2(cv::findNonZero(src, idx));
        return pyopencv_from(idx);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_idx = NULL;
    UMat idx;

    const char* keywords[] = { "src", "idx", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:findNonZero", (char**)keywords, &pyobj_src, &pyobj_idx) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_idx, idx, ArgInfo("idx", 1)) )
    {
        ERRWRAP2(cv::findNonZero(src, idx));
        return pyopencv_from(idx);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_findTransformECC(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_templateImage = NULL;
    Mat templateImage;
    PyObject* pyobj_inputImage = NULL;
    Mat inputImage;
    PyObject* pyobj_warpMatrix = NULL;
    Mat warpMatrix;
    PyObject* pyobj_motionType = NULL;
    int motionType=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;
    PyObject* pyobj_inputMask = NULL;
    Mat inputMask;
    PyObject* pyobj_gaussFiltSize = NULL;
    int gaussFiltSize=0;
    double retval;

    const char* keywords[] = { "templateImage", "inputImage", "warpMatrix", "motionType", "criteria", "inputMask", "gaussFiltSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOO:findTransformECC", (char**)keywords, &pyobj_templateImage, &pyobj_inputImage, &pyobj_warpMatrix, &pyobj_motionType, &pyobj_criteria, &pyobj_inputMask, &pyobj_gaussFiltSize) &&
        pyopencv_to(pyobj_templateImage, templateImage, ArgInfo("templateImage", 0)) &&
        pyopencv_to(pyobj_inputImage, inputImage, ArgInfo("inputImage", 0)) &&
        pyopencv_to(pyobj_warpMatrix, warpMatrix, ArgInfo("warpMatrix", 1)) &&
        pyopencv_to(pyobj_motionType, motionType, ArgInfo("motionType", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to(pyobj_inputMask, inputMask, ArgInfo("inputMask", 0)) &&
        pyopencv_to(pyobj_gaussFiltSize, gaussFiltSize, ArgInfo("gaussFiltSize", 0)) )
    {
        ERRWRAP2(retval = cv::findTransformECC(templateImage, inputImage, warpMatrix, motionType, criteria, inputMask, gaussFiltSize));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(warpMatrix));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_templateImage = NULL;
    UMat templateImage;
    PyObject* pyobj_inputImage = NULL;
    UMat inputImage;
    PyObject* pyobj_warpMatrix = NULL;
    UMat warpMatrix;
    PyObject* pyobj_motionType = NULL;
    int motionType=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;
    PyObject* pyobj_inputMask = NULL;
    UMat inputMask;
    PyObject* pyobj_gaussFiltSize = NULL;
    int gaussFiltSize=0;
    double retval;

    const char* keywords[] = { "templateImage", "inputImage", "warpMatrix", "motionType", "criteria", "inputMask", "gaussFiltSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOO:findTransformECC", (char**)keywords, &pyobj_templateImage, &pyobj_inputImage, &pyobj_warpMatrix, &pyobj_motionType, &pyobj_criteria, &pyobj_inputMask, &pyobj_gaussFiltSize) &&
        pyopencv_to(pyobj_templateImage, templateImage, ArgInfo("templateImage", 0)) &&
        pyopencv_to(pyobj_inputImage, inputImage, ArgInfo("inputImage", 0)) &&
        pyopencv_to(pyobj_warpMatrix, warpMatrix, ArgInfo("warpMatrix", 1)) &&
        pyopencv_to(pyobj_motionType, motionType, ArgInfo("motionType", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to(pyobj_inputMask, inputMask, ArgInfo("inputMask", 0)) &&
        pyopencv_to(pyobj_gaussFiltSize, gaussFiltSize, ArgInfo("gaussFiltSize", 0)) )
    {
        ERRWRAP2(retval = cv::findTransformECC(templateImage, inputImage, warpMatrix, motionType, criteria, inputMask, gaussFiltSize));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(warpMatrix));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fitEllipse(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:fitEllipse", (char**)keywords, &pyobj_points) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipse(points));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:fitEllipse", (char**)keywords, &pyobj_points) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipse(points));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fitEllipseAMS(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:fitEllipseAMS", (char**)keywords, &pyobj_points) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipseAMS(points));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:fitEllipseAMS", (char**)keywords, &pyobj_points) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipseAMS(points));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fitEllipseDirect(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:fitEllipseDirect", (char**)keywords, &pyobj_points) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipseDirect(points));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:fitEllipseDirect", (char**)keywords, &pyobj_points) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipseDirect(points));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fitLine(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    PyObject* pyobj_line = NULL;
    Mat line;
    PyObject* pyobj_distType = NULL;
    int distType=0;
    PyObject* pyobj_param = NULL;
    double param=0;
    PyObject* pyobj_reps = NULL;
    double reps=0;
    PyObject* pyobj_aeps = NULL;
    double aeps=0;

    const char* keywords[] = { "points", "distType", "param", "reps", "aeps", "line", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|O:fitLine", (char**)keywords, &pyobj_points, &pyobj_distType, &pyobj_param, &pyobj_reps, &pyobj_aeps, &pyobj_line) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to(pyobj_line, line, ArgInfo("line", 1)) &&
        pyopencv_to(pyobj_distType, distType, ArgInfo("distType", 0)) &&
        pyopencv_to(pyobj_param, param, ArgInfo("param", 0)) &&
        pyopencv_to(pyobj_reps, reps, ArgInfo("reps", 0)) &&
        pyopencv_to(pyobj_aeps, aeps, ArgInfo("aeps", 0)) )
    {
        ERRWRAP2(cv::fitLine(points, line, distType, param, reps, aeps));
        return pyopencv_from(line);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    PyObject* pyobj_line = NULL;
    UMat line;
    PyObject* pyobj_distType = NULL;
    int distType=0;
    PyObject* pyobj_param = NULL;
    double param=0;
    PyObject* pyobj_reps = NULL;
    double reps=0;
    PyObject* pyobj_aeps = NULL;
    double aeps=0;

    const char* keywords[] = { "points", "distType", "param", "reps", "aeps", "line", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|O:fitLine", (char**)keywords, &pyobj_points, &pyobj_distType, &pyobj_param, &pyobj_reps, &pyobj_aeps, &pyobj_line) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to(pyobj_line, line, ArgInfo("line", 1)) &&
        pyopencv_to(pyobj_distType, distType, ArgInfo("distType", 0)) &&
        pyopencv_to(pyobj_param, param, ArgInfo("param", 0)) &&
        pyopencv_to(pyobj_reps, reps, ArgInfo("reps", 0)) &&
        pyopencv_to(pyobj_aeps, aeps, ArgInfo("aeps", 0)) )
    {
        ERRWRAP2(cv::fitLine(points, line, distType, param, reps, aeps));
        return pyopencv_from(line);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_flip(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flipCode = NULL;
    int flipCode=0;

    const char* keywords[] = { "src", "flipCode", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:flip", (char**)keywords, &pyobj_src, &pyobj_flipCode, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flipCode, flipCode, ArgInfo("flipCode", 0)) )
    {
        ERRWRAP2(cv::flip(src, dst, flipCode));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flipCode = NULL;
    int flipCode=0;

    const char* keywords[] = { "src", "flipCode", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:flip", (char**)keywords, &pyobj_src, &pyobj_flipCode, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flipCode, flipCode, ArgInfo("flipCode", 0)) )
    {
        ERRWRAP2(cv::flip(src, dst, flipCode));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_floodFill(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_seedPoint = NULL;
    Point seedPoint;
    PyObject* pyobj_newVal = NULL;
    Scalar newVal;
    Rect rect;
    PyObject* pyobj_loDiff = NULL;
    Scalar loDiff;
    PyObject* pyobj_upDiff = NULL;
    Scalar upDiff;
    PyObject* pyobj_flags = NULL;
    int flags=4;
    int retval;

    const char* keywords[] = { "image", "mask", "seedPoint", "newVal", "loDiff", "upDiff", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:floodFill", (char**)keywords, &pyobj_image, &pyobj_mask, &pyobj_seedPoint, &pyobj_newVal, &pyobj_loDiff, &pyobj_upDiff, &pyobj_flags) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to(pyobj_seedPoint, seedPoint, ArgInfo("seedPoint", 0)) &&
        pyopencv_to(pyobj_newVal, newVal, ArgInfo("newVal", 0)) &&
        pyopencv_to(pyobj_loDiff, loDiff, ArgInfo("loDiff", 0)) &&
        pyopencv_to(pyobj_upDiff, upDiff, ArgInfo("upDiff", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::floodFill(image, mask, seedPoint, newVal, &rect, loDiff, upDiff, flags));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(image), pyopencv_from(mask), pyopencv_from(rect));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_seedPoint = NULL;
    Point seedPoint;
    PyObject* pyobj_newVal = NULL;
    Scalar newVal;
    Rect rect;
    PyObject* pyobj_loDiff = NULL;
    Scalar loDiff;
    PyObject* pyobj_upDiff = NULL;
    Scalar upDiff;
    PyObject* pyobj_flags = NULL;
    int flags=4;
    int retval;

    const char* keywords[] = { "image", "mask", "seedPoint", "newVal", "loDiff", "upDiff", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:floodFill", (char**)keywords, &pyobj_image, &pyobj_mask, &pyobj_seedPoint, &pyobj_newVal, &pyobj_loDiff, &pyobj_upDiff, &pyobj_flags) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to(pyobj_seedPoint, seedPoint, ArgInfo("seedPoint", 0)) &&
        pyopencv_to(pyobj_newVal, newVal, ArgInfo("newVal", 0)) &&
        pyopencv_to(pyobj_loDiff, loDiff, ArgInfo("loDiff", 0)) &&
        pyopencv_to(pyobj_upDiff, upDiff, ArgInfo("upDiff", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::floodFill(image, mask, seedPoint, newVal, &rect, loDiff, upDiff, flags));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(image), pyopencv_from(mask), pyopencv_from(rect));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_gemm(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src3 = NULL;
    Mat src3;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src1", "src2", "alpha", "src3", "beta", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OO:gemm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_alpha, &pyobj_src3, &pyobj_beta, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_src3, src3, ArgInfo("src3", 0)) &&
        pyopencv_to(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::gemm(src1, src2, alpha, src3, beta, dst, flags));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src3 = NULL;
    UMat src3;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src1", "src2", "alpha", "src3", "beta", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OO:gemm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_alpha, &pyobj_src3, &pyobj_beta, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_src3, src3, ArgInfo("src3", 0)) &&
        pyopencv_to(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::gemm(src1, src2, alpha, src3, beta, dst, flags));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_getAffineTransform(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    Mat retval;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:getAffineTransform", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 0)) )
    {
        ERRWRAP2(retval = cv::getAffineTransform(src, dst));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    Mat retval;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:getAffineTransform", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 0)) )
    {
        ERRWRAP2(retval = cv::getAffineTransform(src, dst));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_getBuildInformation(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    String retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getBuildInformation());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getCPUFeaturesLine(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    std::string retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getCPUFeaturesLine());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getCPUTickCount(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    int64 retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getCPUTickCount());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getDefaultNewCameraMatrix(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_imgsize = NULL;
    Size imgsize;
    PyObject* pyobj_centerPrincipalPoint = NULL;
    bool centerPrincipalPoint=false;
    Mat retval;

    const char* keywords[] = { "cameraMatrix", "imgsize", "centerPrincipalPoint", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:getDefaultNewCameraMatrix", (char**)keywords, &pyobj_cameraMatrix, &pyobj_imgsize, &pyobj_centerPrincipalPoint) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_imgsize, imgsize, ArgInfo("imgsize", 0)) &&
        pyopencv_to(pyobj_centerPrincipalPoint, centerPrincipalPoint, ArgInfo("centerPrincipalPoint", 0)) )
    {
        ERRWRAP2(retval = cv::getDefaultNewCameraMatrix(cameraMatrix, imgsize, centerPrincipalPoint));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_imgsize = NULL;
    Size imgsize;
    PyObject* pyobj_centerPrincipalPoint = NULL;
    bool centerPrincipalPoint=false;
    Mat retval;

    const char* keywords[] = { "cameraMatrix", "imgsize", "centerPrincipalPoint", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:getDefaultNewCameraMatrix", (char**)keywords, &pyobj_cameraMatrix, &pyobj_imgsize, &pyobj_centerPrincipalPoint) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_imgsize, imgsize, ArgInfo("imgsize", 0)) &&
        pyopencv_to(pyobj_centerPrincipalPoint, centerPrincipalPoint, ArgInfo("centerPrincipalPoint", 0)) )
    {
        ERRWRAP2(retval = cv::getDefaultNewCameraMatrix(cameraMatrix, imgsize, centerPrincipalPoint));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_getDerivKernels(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_kx = NULL;
    Mat kx;
    PyObject* pyobj_ky = NULL;
    Mat ky;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_normalize = NULL;
    bool normalize=false;
    PyObject* pyobj_ktype = NULL;
    int ktype=CV_32F;

    const char* keywords[] = { "dx", "dy", "ksize", "kx", "ky", "normalize", "ktype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:getDerivKernels", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_ksize, &pyobj_kx, &pyobj_ky, &pyobj_normalize, &pyobj_ktype) &&
        pyopencv_to(pyobj_kx, kx, ArgInfo("kx", 1)) &&
        pyopencv_to(pyobj_ky, ky, ArgInfo("ky", 1)) &&
        pyopencv_to(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to(pyobj_ktype, ktype, ArgInfo("ktype", 0)) )
    {
        ERRWRAP2(cv::getDerivKernels(kx, ky, dx, dy, ksize, normalize, ktype));
        return Py_BuildValue("(NN)", pyopencv_from(kx), pyopencv_from(ky));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_kx = NULL;
    UMat kx;
    PyObject* pyobj_ky = NULL;
    UMat ky;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_normalize = NULL;
    bool normalize=false;
    PyObject* pyobj_ktype = NULL;
    int ktype=CV_32F;

    const char* keywords[] = { "dx", "dy", "ksize", "kx", "ky", "normalize", "ktype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:getDerivKernels", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_ksize, &pyobj_kx, &pyobj_ky, &pyobj_normalize, &pyobj_ktype) &&
        pyopencv_to(pyobj_kx, kx, ArgInfo("kx", 1)) &&
        pyopencv_to(pyobj_ky, ky, ArgInfo("ky", 1)) &&
        pyopencv_to(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to(pyobj_ktype, ktype, ArgInfo("ktype", 0)) )
    {
        ERRWRAP2(cv::getDerivKernels(kx, ky, dx, dy, ksize, normalize, ktype));
        return Py_BuildValue("(NN)", pyopencv_from(kx), pyopencv_from(ky));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_getFontScaleFromHeight(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_fontFace = NULL;
    int fontFace=0;
    PyObject* pyobj_pixelHeight = NULL;
    int pixelHeight=0;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    double retval;

    const char* keywords[] = { "fontFace", "pixelHeight", "thickness", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:getFontScaleFromHeight", (char**)keywords, &pyobj_fontFace, &pyobj_pixelHeight, &pyobj_thickness) &&
        pyopencv_to(pyobj_fontFace, fontFace, ArgInfo("fontFace", 0)) &&
        pyopencv_to(pyobj_pixelHeight, pixelHeight, ArgInfo("pixelHeight", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) )
    {
        ERRWRAP2(retval = cv::getFontScaleFromHeight(fontFace, pixelHeight, thickness));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getGaborKernel(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_sigma = NULL;
    double sigma=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_lambd = NULL;
    double lambd=0;
    PyObject* pyobj_gamma = NULL;
    double gamma=0;
    PyObject* pyobj_psi = NULL;
    double psi=CV_PI*0.5;
    PyObject* pyobj_ktype = NULL;
    int ktype=CV_64F;
    Mat retval;

    const char* keywords[] = { "ksize", "sigma", "theta", "lambd", "gamma", "psi", "ktype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OO:getGaborKernel", (char**)keywords, &pyobj_ksize, &pyobj_sigma, &pyobj_theta, &pyobj_lambd, &pyobj_gamma, &pyobj_psi, &pyobj_ktype) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_sigma, sigma, ArgInfo("sigma", 0)) &&
        pyopencv_to(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to(pyobj_lambd, lambd, ArgInfo("lambd", 0)) &&
        pyopencv_to(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to(pyobj_psi, psi, ArgInfo("psi", 0)) &&
        pyopencv_to(pyobj_ktype, ktype, ArgInfo("ktype", 0)) )
    {
        ERRWRAP2(retval = cv::getGaborKernel(ksize, sigma, theta, lambd, gamma, psi, ktype));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getGaussianKernel(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_sigma = NULL;
    double sigma=0;
    PyObject* pyobj_ktype = NULL;
    int ktype=CV_64F;
    Mat retval;

    const char* keywords[] = { "ksize", "sigma", "ktype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:getGaussianKernel", (char**)keywords, &pyobj_ksize, &pyobj_sigma, &pyobj_ktype) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_sigma, sigma, ArgInfo("sigma", 0)) &&
        pyopencv_to(pyobj_ktype, ktype, ArgInfo("ktype", 0)) )
    {
        ERRWRAP2(retval = cv::getGaussianKernel(ksize, sigma, ktype));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getHardwareFeatureName(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_feature = NULL;
    int feature=0;
    String retval;

    const char* keywords[] = { "feature", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:getHardwareFeatureName", (char**)keywords, &pyobj_feature) &&
        pyopencv_to(pyobj_feature, feature, ArgInfo("feature", 0)) )
    {
        ERRWRAP2(retval = cv::getHardwareFeatureName(feature));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getNumThreads(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getNumThreads());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getNumberOfCPUs(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getNumberOfCPUs());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getOptimalDFTSize(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_vecsize = NULL;
    int vecsize=0;
    int retval;

    const char* keywords[] = { "vecsize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:getOptimalDFTSize", (char**)keywords, &pyobj_vecsize) &&
        pyopencv_to(pyobj_vecsize, vecsize, ArgInfo("vecsize", 0)) )
    {
        ERRWRAP2(retval = cv::getOptimalDFTSize(vecsize));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getOptimalNewCameraMatrix(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_newImgSize = NULL;
    Size newImgSize;
    Rect validPixROI;
    PyObject* pyobj_centerPrincipalPoint = NULL;
    bool centerPrincipalPoint=false;
    Mat retval;

    const char* keywords[] = { "cameraMatrix", "distCoeffs", "imageSize", "alpha", "newImgSize", "centerPrincipalPoint", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:getOptimalNewCameraMatrix", (char**)keywords, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_imageSize, &pyobj_alpha, &pyobj_newImgSize, &pyobj_centerPrincipalPoint) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_newImgSize, newImgSize, ArgInfo("newImgSize", 0)) &&
        pyopencv_to(pyobj_centerPrincipalPoint, centerPrincipalPoint, ArgInfo("centerPrincipalPoint", 0)) )
    {
        ERRWRAP2(retval = cv::getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, alpha, newImgSize, &validPixROI, centerPrincipalPoint));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(validPixROI));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_newImgSize = NULL;
    Size newImgSize;
    Rect validPixROI;
    PyObject* pyobj_centerPrincipalPoint = NULL;
    bool centerPrincipalPoint=false;
    Mat retval;

    const char* keywords[] = { "cameraMatrix", "distCoeffs", "imageSize", "alpha", "newImgSize", "centerPrincipalPoint", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:getOptimalNewCameraMatrix", (char**)keywords, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_imageSize, &pyobj_alpha, &pyobj_newImgSize, &pyobj_centerPrincipalPoint) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_newImgSize, newImgSize, ArgInfo("newImgSize", 0)) &&
        pyopencv_to(pyobj_centerPrincipalPoint, centerPrincipalPoint, ArgInfo("centerPrincipalPoint", 0)) )
    {
        ERRWRAP2(retval = cv::getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, alpha, newImgSize, &validPixROI, centerPrincipalPoint));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(validPixROI));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_getPerspectiveTransform(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_solveMethod = NULL;
    int solveMethod=DECOMP_LU;
    Mat retval;

    const char* keywords[] = { "src", "dst", "solveMethod", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:getPerspectiveTransform", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_solveMethod) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 0)) &&
        pyopencv_to(pyobj_solveMethod, solveMethod, ArgInfo("solveMethod", 0)) )
    {
        ERRWRAP2(retval = cv::getPerspectiveTransform(src, dst, solveMethod));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_solveMethod = NULL;
    int solveMethod=DECOMP_LU;
    Mat retval;

    const char* keywords[] = { "src", "dst", "solveMethod", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:getPerspectiveTransform", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_solveMethod) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 0)) &&
        pyopencv_to(pyobj_solveMethod, solveMethod, ArgInfo("solveMethod", 0)) )
    {
        ERRWRAP2(retval = cv::getPerspectiveTransform(src, dst, solveMethod));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_getRectSubPix(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_patchSize = NULL;
    Size patchSize;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_patch = NULL;
    Mat patch;
    PyObject* pyobj_patchType = NULL;
    int patchType=-1;

    const char* keywords[] = { "image", "patchSize", "center", "patch", "patchType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:getRectSubPix", (char**)keywords, &pyobj_image, &pyobj_patchSize, &pyobj_center, &pyobj_patch, &pyobj_patchType) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patchSize, patchSize, ArgInfo("patchSize", 0)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_patch, patch, ArgInfo("patch", 1)) &&
        pyopencv_to(pyobj_patchType, patchType, ArgInfo("patchType", 0)) )
    {
        ERRWRAP2(cv::getRectSubPix(image, patchSize, center, patch, patchType));
        return pyopencv_from(patch);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_patchSize = NULL;
    Size patchSize;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_patch = NULL;
    UMat patch;
    PyObject* pyobj_patchType = NULL;
    int patchType=-1;

    const char* keywords[] = { "image", "patchSize", "center", "patch", "patchType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:getRectSubPix", (char**)keywords, &pyobj_image, &pyobj_patchSize, &pyobj_center, &pyobj_patch, &pyobj_patchType) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_patchSize, patchSize, ArgInfo("patchSize", 0)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_patch, patch, ArgInfo("patch", 1)) &&
        pyopencv_to(pyobj_patchType, patchType, ArgInfo("patchType", 0)) )
    {
        ERRWRAP2(cv::getRectSubPix(image, patchSize, center, patch, patchType));
        return pyopencv_from(patch);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_getRotationMatrix2D(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_angle = NULL;
    double angle=0;
    PyObject* pyobj_scale = NULL;
    double scale=0;
    Mat retval;

    const char* keywords[] = { "center", "angle", "scale", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:getRotationMatrix2D", (char**)keywords, &pyobj_center, &pyobj_angle, &pyobj_scale) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) )
    {
        ERRWRAP2(retval = cv::getRotationMatrix2D(center, angle, scale));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getStructuringElement(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_shape = NULL;
    int shape=0;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    Mat retval;

    const char* keywords[] = { "shape", "ksize", "anchor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:getStructuringElement", (char**)keywords, &pyobj_shape, &pyobj_ksize, &pyobj_anchor) &&
        pyopencv_to(pyobj_shape, shape, ArgInfo("shape", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) )
    {
        ERRWRAP2(retval = cv::getStructuringElement(shape, ksize, anchor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getTextSize(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_text = NULL;
    String text;
    PyObject* pyobj_fontFace = NULL;
    int fontFace=0;
    PyObject* pyobj_fontScale = NULL;
    double fontScale=0;
    PyObject* pyobj_thickness = NULL;
    int thickness=0;
    int baseLine;
    Size retval;

    const char* keywords[] = { "text", "fontFace", "fontScale", "thickness", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO:getTextSize", (char**)keywords, &pyobj_text, &pyobj_fontFace, &pyobj_fontScale, &pyobj_thickness) &&
        pyopencv_to(pyobj_text, text, ArgInfo("text", 0)) &&
        pyopencv_to(pyobj_fontFace, fontFace, ArgInfo("fontFace", 0)) &&
        pyopencv_to(pyobj_fontScale, fontScale, ArgInfo("fontScale", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) )
    {
        ERRWRAP2(retval = cv::getTextSize(text, fontFace, fontScale, thickness, &baseLine));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(baseLine));
    }

    return NULL;
}

static PyObject* pyopencv_cv_getThreadNum(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getThreadNum());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getTickCount(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    int64 retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getTickCount());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getTickFrequency(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    double retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getTickFrequency());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getTrackbarPos(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_trackbarname = NULL;
    String trackbarname;
    PyObject* pyobj_winname = NULL;
    String winname;
    int retval;

    const char* keywords[] = { "trackbarname", "winname", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:getTrackbarPos", (char**)keywords, &pyobj_trackbarname, &pyobj_winname) &&
        pyopencv_to(pyobj_trackbarname, trackbarname, ArgInfo("trackbarname", 0)) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) )
    {
        ERRWRAP2(retval = cv::getTrackbarPos(trackbarname, winname));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getValidDisparityROI(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_roi1 = NULL;
    Rect roi1;
    PyObject* pyobj_roi2 = NULL;
    Rect roi2;
    PyObject* pyobj_minDisparity = NULL;
    int minDisparity=0;
    PyObject* pyobj_numberOfDisparities = NULL;
    int numberOfDisparities=0;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    Rect retval;

    const char* keywords[] = { "roi1", "roi2", "minDisparity", "numberOfDisparities", "blockSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO:getValidDisparityROI", (char**)keywords, &pyobj_roi1, &pyobj_roi2, &pyobj_minDisparity, &pyobj_numberOfDisparities, &pyobj_blockSize) &&
        pyopencv_to(pyobj_roi1, roi1, ArgInfo("roi1", 0)) &&
        pyopencv_to(pyobj_roi2, roi2, ArgInfo("roi2", 0)) &&
        pyopencv_to(pyobj_minDisparity, minDisparity, ArgInfo("minDisparity", 0)) &&
        pyopencv_to(pyobj_numberOfDisparities, numberOfDisparities, ArgInfo("numberOfDisparities", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) )
    {
        ERRWRAP2(retval = cv::getValidDisparityROI(roi1, roi2, minDisparity, numberOfDisparities, blockSize));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getVersionMajor(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getVersionMajor());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getVersionMinor(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getVersionMinor());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getVersionRevision(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getVersionRevision());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getVersionString(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    String retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getVersionString());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getWindowImageRect(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_winname = NULL;
    String winname;
    Rect retval;

    const char* keywords[] = { "winname", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:getWindowImageRect", (char**)keywords, &pyobj_winname) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) )
    {
        ERRWRAP2(retval = cv::getWindowImageRect(winname));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getWindowProperty(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_prop_id = NULL;
    int prop_id=0;
    double retval;

    const char* keywords[] = { "winname", "prop_id", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:getWindowProperty", (char**)keywords, &pyobj_winname, &pyobj_prop_id) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_prop_id, prop_id, ArgInfo("prop_id", 0)) )
    {
        ERRWRAP2(retval = cv::getWindowProperty(winname, prop_id));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_goodFeaturesToTrack(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=3;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;

    const char* keywords[] = { "image", "maxCorners", "qualityLevel", "minDistance", "corners", "mask", "blockSize", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:goodFeaturesToTrack", (char**)keywords, &pyobj_image, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_corners, &pyobj_mask, &pyobj_blockSize, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, blockSize, useHarrisDetector, k));
        return pyopencv_from(corners);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=3;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;

    const char* keywords[] = { "image", "maxCorners", "qualityLevel", "minDistance", "corners", "mask", "blockSize", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOO:goodFeaturesToTrack", (char**)keywords, &pyobj_image, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_corners, &pyobj_mask, &pyobj_blockSize, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, blockSize, useHarrisDetector, k));
        return pyopencv_from(corners);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_gradientSize = NULL;
    int gradientSize=0;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;

    const char* keywords[] = { "image", "maxCorners", "qualityLevel", "minDistance", "mask", "blockSize", "gradientSize", "corners", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOO|OOO:goodFeaturesToTrack", (char**)keywords, &pyobj_image, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_mask, &pyobj_blockSize, &pyobj_gradientSize, &pyobj_corners, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_gradientSize, gradientSize, ArgInfo("gradientSize", 0)) &&
        pyopencv_to(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, blockSize, gradientSize, useHarrisDetector, k));
        return pyopencv_from(corners);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_gradientSize = NULL;
    int gradientSize=0;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;

    const char* keywords[] = { "image", "maxCorners", "qualityLevel", "minDistance", "mask", "blockSize", "gradientSize", "corners", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOO|OOO:goodFeaturesToTrack", (char**)keywords, &pyobj_image, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_mask, &pyobj_blockSize, &pyobj_gradientSize, &pyobj_corners, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to(pyobj_gradientSize, gradientSize, ArgInfo("gradientSize", 0)) &&
        pyopencv_to(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, blockSize, gradientSize, useHarrisDetector, k));
        return pyopencv_from(corners);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_grabCut(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_rect = NULL;
    Rect rect;
    PyObject* pyobj_bgdModel = NULL;
    Mat bgdModel;
    PyObject* pyobj_fgdModel = NULL;
    Mat fgdModel;
    PyObject* pyobj_iterCount = NULL;
    int iterCount=0;
    PyObject* pyobj_mode = NULL;
    int mode=GC_EVAL;

    const char* keywords[] = { "img", "mask", "rect", "bgdModel", "fgdModel", "iterCount", "mode", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:grabCut", (char**)keywords, &pyobj_img, &pyobj_mask, &pyobj_rect, &pyobj_bgdModel, &pyobj_fgdModel, &pyobj_iterCount, &pyobj_mode) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to(pyobj_rect, rect, ArgInfo("rect", 0)) &&
        pyopencv_to(pyobj_bgdModel, bgdModel, ArgInfo("bgdModel", 1)) &&
        pyopencv_to(pyobj_fgdModel, fgdModel, ArgInfo("fgdModel", 1)) &&
        pyopencv_to(pyobj_iterCount, iterCount, ArgInfo("iterCount", 0)) &&
        pyopencv_to(pyobj_mode, mode, ArgInfo("mode", 0)) )
    {
        ERRWRAP2(cv::grabCut(img, mask, rect, bgdModel, fgdModel, iterCount, mode));
        return Py_BuildValue("(NNN)", pyopencv_from(mask), pyopencv_from(bgdModel), pyopencv_from(fgdModel));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_rect = NULL;
    Rect rect;
    PyObject* pyobj_bgdModel = NULL;
    UMat bgdModel;
    PyObject* pyobj_fgdModel = NULL;
    UMat fgdModel;
    PyObject* pyobj_iterCount = NULL;
    int iterCount=0;
    PyObject* pyobj_mode = NULL;
    int mode=GC_EVAL;

    const char* keywords[] = { "img", "mask", "rect", "bgdModel", "fgdModel", "iterCount", "mode", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:grabCut", (char**)keywords, &pyobj_img, &pyobj_mask, &pyobj_rect, &pyobj_bgdModel, &pyobj_fgdModel, &pyobj_iterCount, &pyobj_mode) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to(pyobj_rect, rect, ArgInfo("rect", 0)) &&
        pyopencv_to(pyobj_bgdModel, bgdModel, ArgInfo("bgdModel", 1)) &&
        pyopencv_to(pyobj_fgdModel, fgdModel, ArgInfo("fgdModel", 1)) &&
        pyopencv_to(pyobj_iterCount, iterCount, ArgInfo("iterCount", 0)) &&
        pyopencv_to(pyobj_mode, mode, ArgInfo("mode", 0)) )
    {
        ERRWRAP2(cv::grabCut(img, mask, rect, bgdModel, fgdModel, iterCount, mode));
        return Py_BuildValue("(NNN)", pyopencv_from(mask), pyopencv_from(bgdModel), pyopencv_from(fgdModel));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_groupRectangles(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_rectList = NULL;
    vector_Rect rectList;
    vector_int weights;
    PyObject* pyobj_groupThreshold = NULL;
    int groupThreshold=0;
    PyObject* pyobj_eps = NULL;
    double eps=0.2;

    const char* keywords[] = { "rectList", "groupThreshold", "eps", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:groupRectangles", (char**)keywords, &pyobj_rectList, &pyobj_groupThreshold, &pyobj_eps) &&
        pyopencv_to(pyobj_rectList, rectList, ArgInfo("rectList", 1)) &&
        pyopencv_to(pyobj_groupThreshold, groupThreshold, ArgInfo("groupThreshold", 0)) &&
        pyopencv_to(pyobj_eps, eps, ArgInfo("eps", 0)) )
    {
        ERRWRAP2(cv::groupRectangles(rectList, weights, groupThreshold, eps));
        return Py_BuildValue("(NN)", pyopencv_from(rectList), pyopencv_from(weights));
    }

    return NULL;
}

static PyObject* pyopencv_cv_haveImageReader(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_filename = NULL;
    String filename;
    bool retval;

    const char* keywords[] = { "filename", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:haveImageReader", (char**)keywords, &pyobj_filename) &&
        pyopencv_to(pyobj_filename, filename, ArgInfo("filename", 0)) )
    {
        ERRWRAP2(retval = cv::haveImageReader(filename));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_haveImageWriter(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_filename = NULL;
    String filename;
    bool retval;

    const char* keywords[] = { "filename", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:haveImageWriter", (char**)keywords, &pyobj_filename) &&
        pyopencv_to(pyobj_filename, filename, ArgInfo("filename", 0)) )
    {
        ERRWRAP2(retval = cv::haveImageWriter(filename));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_haveOpenVX(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    bool retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::haveOpenVX());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_hconcat(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    vector_Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:hconcat", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::hconcat(src, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    vector_UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:hconcat", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::hconcat(src, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_idct(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:idct", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::idct(src, dst, flags));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:idct", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::idct(src, dst, flags));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_idft(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_nonzeroRows = NULL;
    int nonzeroRows=0;

    const char* keywords[] = { "src", "dst", "flags", "nonzeroRows", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:idft", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags, &pyobj_nonzeroRows) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_nonzeroRows, nonzeroRows, ArgInfo("nonzeroRows", 0)) )
    {
        ERRWRAP2(cv::idft(src, dst, flags, nonzeroRows));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_nonzeroRows = NULL;
    int nonzeroRows=0;

    const char* keywords[] = { "src", "dst", "flags", "nonzeroRows", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:idft", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags, &pyobj_nonzeroRows) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_nonzeroRows, nonzeroRows, ArgInfo("nonzeroRows", 0)) )
    {
        ERRWRAP2(cv::idft(src, dst, flags, nonzeroRows));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_illuminationChange(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_alpha = NULL;
    float alpha=0.2f;
    PyObject* pyobj_beta = NULL;
    float beta=0.4f;

    const char* keywords[] = { "src", "mask", "dst", "alpha", "beta", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:illuminationChange", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst, &pyobj_alpha, &pyobj_beta) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_beta, beta, ArgInfo("beta", 0)) )
    {
        ERRWRAP2(cv::illuminationChange(src, mask, dst, alpha, beta));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_alpha = NULL;
    float alpha=0.2f;
    PyObject* pyobj_beta = NULL;
    float beta=0.4f;

    const char* keywords[] = { "src", "mask", "dst", "alpha", "beta", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:illuminationChange", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst, &pyobj_alpha, &pyobj_beta) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_beta, beta, ArgInfo("beta", 0)) )
    {
        ERRWRAP2(cv::illuminationChange(src, mask, dst, alpha, beta));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_imdecode(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_buf = NULL;
    Mat buf;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:imdecode", (char**)keywords, &pyobj_buf, &pyobj_flags) &&
        pyopencv_to(pyobj_buf, buf, ArgInfo("buf", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imdecode(buf, flags));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_buf = NULL;
    UMat buf;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:imdecode", (char**)keywords, &pyobj_buf, &pyobj_flags) &&
        pyopencv_to(pyobj_buf, buf, ArgInfo("buf", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imdecode(buf, flags));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_imencode(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_ext = NULL;
    String ext;
    PyObject* pyobj_img = NULL;
    Mat img;
    vector_uchar buf;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "ext", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:imencode", (char**)keywords, &pyobj_ext, &pyobj_img, &pyobj_params) &&
        pyopencv_to(pyobj_ext, ext, ArgInfo("ext", 0)) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imencode(ext, img, buf, params));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(buf));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_ext = NULL;
    String ext;
    PyObject* pyobj_img = NULL;
    UMat img;
    vector_uchar buf;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "ext", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:imencode", (char**)keywords, &pyobj_ext, &pyobj_img, &pyobj_params) &&
        pyopencv_to(pyobj_ext, ext, ArgInfo("ext", 0)) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imencode(ext, img, buf, params));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(buf));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_imread(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;
    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:imread", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
        pyopencv_to(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imread(filename, flags));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_imreadmulti(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_mats = NULL;
    vector_Mat mats;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    bool retval;

    const char* keywords[] = { "filename", "mats", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:imreadmulti", (char**)keywords, &pyobj_filename, &pyobj_mats, &pyobj_flags) &&
        pyopencv_to(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to(pyobj_mats, mats, ArgInfo("mats", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imreadmulti(filename, mats, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mats));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_mats = NULL;
    vector_Mat mats;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    bool retval;

    const char* keywords[] = { "filename", "mats", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:imreadmulti", (char**)keywords, &pyobj_filename, &pyobj_mats, &pyobj_flags) &&
        pyopencv_to(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to(pyobj_mats, mats, ArgInfo("mats", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imreadmulti(filename, mats, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mats));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_imshow(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_mat = NULL;
    Mat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:imshow", (char**)keywords, &pyobj_winname, &pyobj_mat) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_mat = NULL;
    UMat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:imshow", (char**)keywords, &pyobj_winname, &pyobj_mat) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_imwrite(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:imwrite", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        pyopencv_to(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwrite(filename, img, params));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:imwrite", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        pyopencv_to(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwrite(filename, img, params));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_inRange(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_lowerb = NULL;
    Mat lowerb;
    PyObject* pyobj_upperb = NULL;
    Mat upperb;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "lowerb", "upperb", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:inRange", (char**)keywords, &pyobj_src, &pyobj_lowerb, &pyobj_upperb, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_lowerb, lowerb, ArgInfo("lowerb", 0)) &&
        pyopencv_to(pyobj_upperb, upperb, ArgInfo("upperb", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::inRange(src, lowerb, upperb, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_lowerb = NULL;
    UMat lowerb;
    PyObject* pyobj_upperb = NULL;
    UMat upperb;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "lowerb", "upperb", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:inRange", (char**)keywords, &pyobj_src, &pyobj_lowerb, &pyobj_upperb, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_lowerb, lowerb, ArgInfo("lowerb", 0)) &&
        pyopencv_to(pyobj_upperb, upperb, ArgInfo("upperb", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::inRange(src, lowerb, upperb, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_initCameraMatrix2D(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_Mat imagePoints;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_aspectRatio = NULL;
    double aspectRatio=1.0;
    Mat retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "aspectRatio", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:initCameraMatrix2D", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_imageSize, &pyobj_aspectRatio) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_aspectRatio, aspectRatio, ArgInfo("aspectRatio", 0)) )
    {
        ERRWRAP2(retval = cv::initCameraMatrix2D(objectPoints, imagePoints, imageSize, aspectRatio));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_UMat imagePoints;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_aspectRatio = NULL;
    double aspectRatio=1.0;
    Mat retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "aspectRatio", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:initCameraMatrix2D", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_imageSize, &pyobj_aspectRatio) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_aspectRatio, aspectRatio, ArgInfo("aspectRatio", 0)) )
    {
        ERRWRAP2(retval = cv::initCameraMatrix2D(objectPoints, imagePoints, imageSize, aspectRatio));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_initUndistortRectifyMap(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_newCameraMatrix = NULL;
    Mat newCameraMatrix;
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_m1type = NULL;
    int m1type=0;
    PyObject* pyobj_map1 = NULL;
    Mat map1;
    PyObject* pyobj_map2 = NULL;
    Mat map2;

    const char* keywords[] = { "cameraMatrix", "distCoeffs", "R", "newCameraMatrix", "size", "m1type", "map1", "map2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OO:initUndistortRectifyMap", (char**)keywords, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_R, &pyobj_newCameraMatrix, &pyobj_size, &pyobj_m1type, &pyobj_map1, &pyobj_map2) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_newCameraMatrix, newCameraMatrix, ArgInfo("newCameraMatrix", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to(pyobj_m1type, m1type, ArgInfo("m1type", 0)) &&
        pyopencv_to(pyobj_map1, map1, ArgInfo("map1", 1)) &&
        pyopencv_to(pyobj_map2, map2, ArgInfo("map2", 1)) )
    {
        ERRWRAP2(cv::initUndistortRectifyMap(cameraMatrix, distCoeffs, R, newCameraMatrix, size, m1type, map1, map2));
        return Py_BuildValue("(NN)", pyopencv_from(map1), pyopencv_from(map2));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_newCameraMatrix = NULL;
    UMat newCameraMatrix;
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_m1type = NULL;
    int m1type=0;
    PyObject* pyobj_map1 = NULL;
    UMat map1;
    PyObject* pyobj_map2 = NULL;
    UMat map2;

    const char* keywords[] = { "cameraMatrix", "distCoeffs", "R", "newCameraMatrix", "size", "m1type", "map1", "map2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OO:initUndistortRectifyMap", (char**)keywords, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_R, &pyobj_newCameraMatrix, &pyobj_size, &pyobj_m1type, &pyobj_map1, &pyobj_map2) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_newCameraMatrix, newCameraMatrix, ArgInfo("newCameraMatrix", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to(pyobj_m1type, m1type, ArgInfo("m1type", 0)) &&
        pyopencv_to(pyobj_map1, map1, ArgInfo("map1", 1)) &&
        pyopencv_to(pyobj_map2, map2, ArgInfo("map2", 1)) )
    {
        ERRWRAP2(cv::initUndistortRectifyMap(cameraMatrix, distCoeffs, R, newCameraMatrix, size, m1type, map1, map2));
        return Py_BuildValue("(NN)", pyopencv_from(map1), pyopencv_from(map2));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_inpaint(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_inpaintMask = NULL;
    Mat inpaintMask;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_inpaintRadius = NULL;
    double inpaintRadius=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "inpaintMask", "inpaintRadius", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:inpaint", (char**)keywords, &pyobj_src, &pyobj_inpaintMask, &pyobj_inpaintRadius, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_inpaintMask, inpaintMask, ArgInfo("inpaintMask", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_inpaintRadius, inpaintRadius, ArgInfo("inpaintRadius", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::inpaint(src, inpaintMask, dst, inpaintRadius, flags));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_inpaintMask = NULL;
    UMat inpaintMask;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_inpaintRadius = NULL;
    double inpaintRadius=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "inpaintMask", "inpaintRadius", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:inpaint", (char**)keywords, &pyobj_src, &pyobj_inpaintMask, &pyobj_inpaintRadius, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_inpaintMask, inpaintMask, ArgInfo("inpaintMask", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_inpaintRadius, inpaintRadius, ArgInfo("inpaintRadius", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::inpaint(src, inpaintMask, dst, inpaintRadius, flags));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_insertChannel(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_coi = NULL;
    int coi=0;

    const char* keywords[] = { "src", "dst", "coi", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:insertChannel", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_coi) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_coi, coi, ArgInfo("coi", 0)) )
    {
        ERRWRAP2(cv::insertChannel(src, dst, coi));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_coi = NULL;
    int coi=0;

    const char* keywords[] = { "src", "dst", "coi", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:insertChannel", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_coi) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_coi, coi, ArgInfo("coi", 0)) )
    {
        ERRWRAP2(cv::insertChannel(src, dst, coi));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_integral(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_sum = NULL;
    Mat sum;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;

    const char* keywords[] = { "src", "sum", "sdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:integral", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sdepth) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sdepth));
        return pyopencv_from(sum);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_sum = NULL;
    UMat sum;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;

    const char* keywords[] = { "src", "sum", "sdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:integral", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sdepth) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sdepth));
        return pyopencv_from(sum);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_integral2(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_sum = NULL;
    Mat sum;
    PyObject* pyobj_sqsum = NULL;
    Mat sqsum;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;
    PyObject* pyobj_sqdepth = NULL;
    int sqdepth=-1;

    const char* keywords[] = { "src", "sum", "sqsum", "sdepth", "sqdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:integral2", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sqsum, &pyobj_sdepth, &pyobj_sqdepth) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) &&
        pyopencv_to(pyobj_sqdepth, sqdepth, ArgInfo("sqdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sqsum, sdepth, sqdepth));
        return Py_BuildValue("(NN)", pyopencv_from(sum), pyopencv_from(sqsum));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_sum = NULL;
    UMat sum;
    PyObject* pyobj_sqsum = NULL;
    UMat sqsum;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;
    PyObject* pyobj_sqdepth = NULL;
    int sqdepth=-1;

    const char* keywords[] = { "src", "sum", "sqsum", "sdepth", "sqdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:integral2", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sqsum, &pyobj_sdepth, &pyobj_sqdepth) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) &&
        pyopencv_to(pyobj_sqdepth, sqdepth, ArgInfo("sqdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sqsum, sdepth, sqdepth));
        return Py_BuildValue("(NN)", pyopencv_from(sum), pyopencv_from(sqsum));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_integral3(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_sum = NULL;
    Mat sum;
    PyObject* pyobj_sqsum = NULL;
    Mat sqsum;
    PyObject* pyobj_tilted = NULL;
    Mat tilted;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;
    PyObject* pyobj_sqdepth = NULL;
    int sqdepth=-1;

    const char* keywords[] = { "src", "sum", "sqsum", "tilted", "sdepth", "sqdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOO:integral3", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sqsum, &pyobj_tilted, &pyobj_sdepth, &pyobj_sqdepth) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to(pyobj_tilted, tilted, ArgInfo("tilted", 1)) &&
        pyopencv_to(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) &&
        pyopencv_to(pyobj_sqdepth, sqdepth, ArgInfo("sqdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sqsum, tilted, sdepth, sqdepth));
        return Py_BuildValue("(NNN)", pyopencv_from(sum), pyopencv_from(sqsum), pyopencv_from(tilted));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_sum = NULL;
    UMat sum;
    PyObject* pyobj_sqsum = NULL;
    UMat sqsum;
    PyObject* pyobj_tilted = NULL;
    UMat tilted;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;
    PyObject* pyobj_sqdepth = NULL;
    int sqdepth=-1;

    const char* keywords[] = { "src", "sum", "sqsum", "tilted", "sdepth", "sqdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOO:integral3", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sqsum, &pyobj_tilted, &pyobj_sdepth, &pyobj_sqdepth) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to(pyobj_tilted, tilted, ArgInfo("tilted", 1)) &&
        pyopencv_to(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) &&
        pyopencv_to(pyobj_sqdepth, sqdepth, ArgInfo("sqdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sqsum, tilted, sdepth, sqdepth));
        return Py_BuildValue("(NNN)", pyopencv_from(sum), pyopencv_from(sqsum), pyopencv_from(tilted));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_intersectConvexConvex(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj__p1 = NULL;
    Mat _p1;
    PyObject* pyobj__p2 = NULL;
    Mat _p2;
    PyObject* pyobj__p12 = NULL;
    Mat _p12;
    PyObject* pyobj_handleNested = NULL;
    bool handleNested=true;
    float retval;

    const char* keywords[] = { "_p1", "_p2", "_p12", "handleNested", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:intersectConvexConvex", (char**)keywords, &pyobj__p1, &pyobj__p2, &pyobj__p12, &pyobj_handleNested) &&
        pyopencv_to(pyobj__p1, _p1, ArgInfo("_p1", 0)) &&
        pyopencv_to(pyobj__p2, _p2, ArgInfo("_p2", 0)) &&
        pyopencv_to(pyobj__p12, _p12, ArgInfo("_p12", 1)) &&
        pyopencv_to(pyobj_handleNested, handleNested, ArgInfo("handleNested", 0)) )
    {
        ERRWRAP2(retval = cv::intersectConvexConvex(_p1, _p2, _p12, handleNested));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(_p12));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj__p1 = NULL;
    UMat _p1;
    PyObject* pyobj__p2 = NULL;
    UMat _p2;
    PyObject* pyobj__p12 = NULL;
    UMat _p12;
    PyObject* pyobj_handleNested = NULL;
    bool handleNested=true;
    float retval;

    const char* keywords[] = { "_p1", "_p2", "_p12", "handleNested", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:intersectConvexConvex", (char**)keywords, &pyobj__p1, &pyobj__p2, &pyobj__p12, &pyobj_handleNested) &&
        pyopencv_to(pyobj__p1, _p1, ArgInfo("_p1", 0)) &&
        pyopencv_to(pyobj__p2, _p2, ArgInfo("_p2", 0)) &&
        pyopencv_to(pyobj__p12, _p12, ArgInfo("_p12", 1)) &&
        pyopencv_to(pyobj_handleNested, handleNested, ArgInfo("handleNested", 0)) )
    {
        ERRWRAP2(retval = cv::intersectConvexConvex(_p1, _p2, _p12, handleNested));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(_p12));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_invert(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=DECOMP_LU;
    double retval;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:invert", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::invert(src, dst, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=DECOMP_LU;
    double retval;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:invert", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::invert(src, dst, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_invertAffineTransform(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_iM = NULL;
    Mat iM;

    const char* keywords[] = { "M", "iM", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:invertAffineTransform", (char**)keywords, &pyobj_M, &pyobj_iM) &&
        pyopencv_to(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to(pyobj_iM, iM, ArgInfo("iM", 1)) )
    {
        ERRWRAP2(cv::invertAffineTransform(M, iM));
        return pyopencv_from(iM);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_iM = NULL;
    UMat iM;

    const char* keywords[] = { "M", "iM", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:invertAffineTransform", (char**)keywords, &pyobj_M, &pyobj_iM) &&
        pyopencv_to(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to(pyobj_iM, iM, ArgInfo("iM", 1)) )
    {
        ERRWRAP2(cv::invertAffineTransform(M, iM));
        return pyopencv_from(iM);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_isContourConvex(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_contour = NULL;
    Mat contour;
    bool retval;

    const char* keywords[] = { "contour", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:isContourConvex", (char**)keywords, &pyobj_contour) &&
        pyopencv_to(pyobj_contour, contour, ArgInfo("contour", 0)) )
    {
        ERRWRAP2(retval = cv::isContourConvex(contour));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_contour = NULL;
    UMat contour;
    bool retval;

    const char* keywords[] = { "contour", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:isContourConvex", (char**)keywords, &pyobj_contour) &&
        pyopencv_to(pyobj_contour, contour, ArgInfo("contour", 0)) )
    {
        ERRWRAP2(retval = cv::isContourConvex(contour));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_kmeans(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_K = NULL;
    int K=0;
    PyObject* pyobj_bestLabels = NULL;
    Mat bestLabels;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;
    PyObject* pyobj_attempts = NULL;
    int attempts=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_centers = NULL;
    Mat centers;
    double retval;

    const char* keywords[] = { "data", "K", "bestLabels", "criteria", "attempts", "flags", "centers", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:kmeans", (char**)keywords, &pyobj_data, &pyobj_K, &pyobj_bestLabels, &pyobj_criteria, &pyobj_attempts, &pyobj_flags, &pyobj_centers) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_bestLabels, bestLabels, ArgInfo("bestLabels", 1)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to(pyobj_attempts, attempts, ArgInfo("attempts", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_centers, centers, ArgInfo("centers", 1)) )
    {
        ERRWRAP2(retval = cv::kmeans(data, K, bestLabels, criteria, attempts, flags, centers));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(bestLabels), pyopencv_from(centers));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_K = NULL;
    int K=0;
    PyObject* pyobj_bestLabels = NULL;
    UMat bestLabels;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;
    PyObject* pyobj_attempts = NULL;
    int attempts=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_centers = NULL;
    UMat centers;
    double retval;

    const char* keywords[] = { "data", "K", "bestLabels", "criteria", "attempts", "flags", "centers", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:kmeans", (char**)keywords, &pyobj_data, &pyobj_K, &pyobj_bestLabels, &pyobj_criteria, &pyobj_attempts, &pyobj_flags, &pyobj_centers) &&
        pyopencv_to(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_bestLabels, bestLabels, ArgInfo("bestLabels", 1)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to(pyobj_attempts, attempts, ArgInfo("attempts", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_centers, centers, ArgInfo("centers", 1)) )
    {
        ERRWRAP2(retval = cv::kmeans(data, K, bestLabels, criteria, attempts, flags, centers));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(bestLabels), pyopencv_from(centers));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_line(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:line", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::line(img, pt1, pt2, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:line", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::line(img, pt1, pt2, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_linearPolar(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_maxRadius = NULL;
    double maxRadius=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "center", "maxRadius", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:linearPolar", (char**)keywords, &pyobj_src, &pyobj_center, &pyobj_maxRadius, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::linearPolar(src, dst, center, maxRadius, flags));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_maxRadius = NULL;
    double maxRadius=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "center", "maxRadius", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:linearPolar", (char**)keywords, &pyobj_src, &pyobj_center, &pyobj_maxRadius, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::linearPolar(src, dst, center, maxRadius, flags));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_log(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:log", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::log(src, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:log", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::log(src, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_logPolar(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_M = NULL;
    double M=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "center", "M", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:logPolar", (char**)keywords, &pyobj_src, &pyobj_center, &pyobj_M, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::logPolar(src, dst, center, M, flags));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_M = NULL;
    double M=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "center", "M", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:logPolar", (char**)keywords, &pyobj_src, &pyobj_center, &pyobj_M, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::logPolar(src, dst, center, M, flags));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_magnitude(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;

    const char* keywords[] = { "x", "y", "magnitude", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:magnitude", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude) &&
        pyopencv_to(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) )
    {
        ERRWRAP2(cv::magnitude(x, y, magnitude));
        return pyopencv_from(magnitude);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;

    const char* keywords[] = { "x", "y", "magnitude", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:magnitude", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude) &&
        pyopencv_to(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) )
    {
        ERRWRAP2(cv::magnitude(x, y, magnitude));
        return pyopencv_from(magnitude);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_matMulDeriv(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_A = NULL;
    Mat A;
    PyObject* pyobj_B = NULL;
    Mat B;
    PyObject* pyobj_dABdA = NULL;
    Mat dABdA;
    PyObject* pyobj_dABdB = NULL;
    Mat dABdB;

    const char* keywords[] = { "A", "B", "dABdA", "dABdB", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:matMulDeriv", (char**)keywords, &pyobj_A, &pyobj_B, &pyobj_dABdA, &pyobj_dABdB) &&
        pyopencv_to(pyobj_A, A, ArgInfo("A", 0)) &&
        pyopencv_to(pyobj_B, B, ArgInfo("B", 0)) &&
        pyopencv_to(pyobj_dABdA, dABdA, ArgInfo("dABdA", 1)) &&
        pyopencv_to(pyobj_dABdB, dABdB, ArgInfo("dABdB", 1)) )
    {
        ERRWRAP2(cv::matMulDeriv(A, B, dABdA, dABdB));
        return Py_BuildValue("(NN)", pyopencv_from(dABdA), pyopencv_from(dABdB));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_A = NULL;
    UMat A;
    PyObject* pyobj_B = NULL;
    UMat B;
    PyObject* pyobj_dABdA = NULL;
    UMat dABdA;
    PyObject* pyobj_dABdB = NULL;
    UMat dABdB;

    const char* keywords[] = { "A", "B", "dABdA", "dABdB", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:matMulDeriv", (char**)keywords, &pyobj_A, &pyobj_B, &pyobj_dABdA, &pyobj_dABdB) &&
        pyopencv_to(pyobj_A, A, ArgInfo("A", 0)) &&
        pyopencv_to(pyobj_B, B, ArgInfo("B", 0)) &&
        pyopencv_to(pyobj_dABdA, dABdA, ArgInfo("dABdA", 1)) &&
        pyopencv_to(pyobj_dABdB, dABdB, ArgInfo("dABdB", 1)) )
    {
        ERRWRAP2(cv::matMulDeriv(A, B, dABdA, dABdB));
        return Py_BuildValue("(NN)", pyopencv_from(dABdA), pyopencv_from(dABdB));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_matchShapes(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_contour1 = NULL;
    Mat contour1;
    PyObject* pyobj_contour2 = NULL;
    Mat contour2;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_parameter = NULL;
    double parameter=0;
    double retval;

    const char* keywords[] = { "contour1", "contour2", "method", "parameter", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO:matchShapes", (char**)keywords, &pyobj_contour1, &pyobj_contour2, &pyobj_method, &pyobj_parameter) &&
        pyopencv_to(pyobj_contour1, contour1, ArgInfo("contour1", 0)) &&
        pyopencv_to(pyobj_contour2, contour2, ArgInfo("contour2", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_parameter, parameter, ArgInfo("parameter", 0)) )
    {
        ERRWRAP2(retval = cv::matchShapes(contour1, contour2, method, parameter));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_contour1 = NULL;
    UMat contour1;
    PyObject* pyobj_contour2 = NULL;
    UMat contour2;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_parameter = NULL;
    double parameter=0;
    double retval;

    const char* keywords[] = { "contour1", "contour2", "method", "parameter", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO:matchShapes", (char**)keywords, &pyobj_contour1, &pyobj_contour2, &pyobj_method, &pyobj_parameter) &&
        pyopencv_to(pyobj_contour1, contour1, ArgInfo("contour1", 0)) &&
        pyopencv_to(pyobj_contour2, contour2, ArgInfo("contour2", 0)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_parameter, parameter, ArgInfo("parameter", 0)) )
    {
        ERRWRAP2(retval = cv::matchShapes(contour1, contour2, method, parameter));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_matchTemplate(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_templ = NULL;
    Mat templ;
    PyObject* pyobj_result = NULL;
    Mat result;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "image", "templ", "method", "result", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:matchTemplate", (char**)keywords, &pyobj_image, &pyobj_templ, &pyobj_method, &pyobj_result, &pyobj_mask) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::matchTemplate(image, templ, result, method, mask));
        return pyopencv_from(result);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_templ = NULL;
    UMat templ;
    PyObject* pyobj_result = NULL;
    UMat result;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "image", "templ", "method", "result", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:matchTemplate", (char**)keywords, &pyobj_image, &pyobj_templ, &pyobj_method, &pyobj_result, &pyobj_mask) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::matchTemplate(image, templ, result, method, mask));
        return pyopencv_from(result);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_max(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:max", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::max(src1, src2, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:max", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::max(src1, src2, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_mean(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:mean", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::mean(src, mask));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:mean", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::mean(src, mask));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_meanShift(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_probImage = NULL;
    Mat probImage;
    PyObject* pyobj_window = NULL;
    Rect window;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;
    int retval;

    const char* keywords[] = { "probImage", "window", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:meanShift", (char**)keywords, &pyobj_probImage, &pyobj_window, &pyobj_criteria) &&
        pyopencv_to(pyobj_probImage, probImage, ArgInfo("probImage", 0)) &&
        pyopencv_to(pyobj_window, window, ArgInfo("window", 1)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::meanShift(probImage, window, criteria));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(window));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_probImage = NULL;
    UMat probImage;
    PyObject* pyobj_window = NULL;
    Rect window;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;
    int retval;

    const char* keywords[] = { "probImage", "window", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:meanShift", (char**)keywords, &pyobj_probImage, &pyobj_window, &pyobj_criteria) &&
        pyopencv_to(pyobj_probImage, probImage, ArgInfo("probImage", 0)) &&
        pyopencv_to(pyobj_window, window, ArgInfo("window", 1)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::meanShift(probImage, window, criteria));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(window));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_meanStdDev(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_stddev = NULL;
    Mat stddev;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "mean", "stddev", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:meanStdDev", (char**)keywords, &pyobj_src, &pyobj_mean, &pyobj_stddev, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_stddev, stddev, ArgInfo("stddev", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::meanStdDev(src, mean, stddev, mask));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(stddev));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_stddev = NULL;
    UMat stddev;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "mean", "stddev", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:meanStdDev", (char**)keywords, &pyobj_src, &pyobj_mean, &pyobj_stddev, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to(pyobj_stddev, stddev, ArgInfo("stddev", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::meanStdDev(src, mean, stddev, mask));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(stddev));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_medianBlur(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;

    const char* keywords[] = { "src", "ksize", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:medianBlur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) )
    {
        ERRWRAP2(cv::medianBlur(src, dst, ksize));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;

    const char* keywords[] = { "src", "ksize", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:medianBlur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) )
    {
        ERRWRAP2(cv::medianBlur(src, dst, ksize));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_merge(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_mv = NULL;
    vector_Mat mv;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "mv", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:merge", (char**)keywords, &pyobj_mv, &pyobj_dst) &&
        pyopencv_to(pyobj_mv, mv, ArgInfo("mv", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::merge(mv, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_mv = NULL;
    vector_UMat mv;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "mv", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:merge", (char**)keywords, &pyobj_mv, &pyobj_dst) &&
        pyopencv_to(pyobj_mv, mv, ArgInfo("mv", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::merge(mv, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_min(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:min", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::min(src1, src2, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:min", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::min(src1, src2, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_minAreaRect(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:minAreaRect", (char**)keywords, &pyobj_points) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::minAreaRect(points));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:minAreaRect", (char**)keywords, &pyobj_points) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::minAreaRect(points));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_minEnclosingCircle(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    Point2f center;
    float radius;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:minEnclosingCircle", (char**)keywords, &pyobj_points) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(cv::minEnclosingCircle(points, center, radius));
        return Py_BuildValue("(NN)", pyopencv_from(center), pyopencv_from(radius));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    Point2f center;
    float radius;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:minEnclosingCircle", (char**)keywords, &pyobj_points) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(cv::minEnclosingCircle(points, center, radius));
        return Py_BuildValue("(NN)", pyopencv_from(center), pyopencv_from(radius));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_minEnclosingTriangle(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    PyObject* pyobj_triangle = NULL;
    Mat triangle;
    double retval;

    const char* keywords[] = { "points", "triangle", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:minEnclosingTriangle", (char**)keywords, &pyobj_points, &pyobj_triangle) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to(pyobj_triangle, triangle, ArgInfo("triangle", 1)) )
    {
        ERRWRAP2(retval = cv::minEnclosingTriangle(points, triangle));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(triangle));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    PyObject* pyobj_triangle = NULL;
    UMat triangle;
    double retval;

    const char* keywords[] = { "points", "triangle", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:minEnclosingTriangle", (char**)keywords, &pyobj_points, &pyobj_triangle) &&
        pyopencv_to(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to(pyobj_triangle, triangle, ArgInfo("triangle", 1)) )
    {
        ERRWRAP2(retval = cv::minEnclosingTriangle(points, triangle));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(triangle));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_minMaxLoc(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:minMaxLoc", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(minVal), pyopencv_from(maxVal), pyopencv_from(minLoc), pyopencv_from(maxLoc));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:minMaxLoc", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(minVal), pyopencv_from(maxVal), pyopencv_from(minLoc), pyopencv_from(maxLoc));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_mixChannels(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    vector_Mat src;
    PyObject* pyobj_dst = NULL;
    vector_Mat dst;
    PyObject* pyobj_fromTo = NULL;
    vector_int fromTo;

    const char* keywords[] = { "src", "dst", "fromTo", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:mixChannels", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_fromTo) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_fromTo, fromTo, ArgInfo("fromTo", 0)) )
    {
        ERRWRAP2(cv::mixChannels(src, dst, fromTo));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    vector_UMat src;
    PyObject* pyobj_dst = NULL;
    vector_UMat dst;
    PyObject* pyobj_fromTo = NULL;
    vector_int fromTo;

    const char* keywords[] = { "src", "dst", "fromTo", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:mixChannels", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_fromTo) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_fromTo, fromTo, ArgInfo("fromTo", 0)) )
    {
        ERRWRAP2(cv::mixChannels(src, dst, fromTo));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_moments(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_array = NULL;
    Mat array;
    PyObject* pyobj_binaryImage = NULL;
    bool binaryImage=false;
    Moments retval;

    const char* keywords[] = { "array", "binaryImage", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:moments", (char**)keywords, &pyobj_array, &pyobj_binaryImage) &&
        pyopencv_to(pyobj_array, array, ArgInfo("array", 0)) &&
        pyopencv_to(pyobj_binaryImage, binaryImage, ArgInfo("binaryImage", 0)) )
    {
        ERRWRAP2(retval = cv::moments(array, binaryImage));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_array = NULL;
    UMat array;
    PyObject* pyobj_binaryImage = NULL;
    bool binaryImage=false;
    Moments retval;

    const char* keywords[] = { "array", "binaryImage", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:moments", (char**)keywords, &pyobj_array, &pyobj_binaryImage) &&
        pyopencv_to(pyobj_array, array, ArgInfo("array", 0)) &&
        pyopencv_to(pyobj_binaryImage, binaryImage, ArgInfo("binaryImage", 0)) )
    {
        ERRWRAP2(retval = cv::moments(array, binaryImage));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_morphologyEx(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_op = NULL;
    int op=0;
    PyObject* pyobj_kernel = NULL;
    Mat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "op", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOOO:morphologyEx", (char**)keywords, &pyobj_src, &pyobj_op, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_op, op, ArgInfo("op", 0)) &&
        pyopencv_to(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::morphologyEx(src, dst, op, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_op = NULL;
    int op=0;
    PyObject* pyobj_kernel = NULL;
    UMat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "op", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOOO:morphologyEx", (char**)keywords, &pyobj_src, &pyobj_op, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_op, op, ArgInfo("op", 0)) &&
        pyopencv_to(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::morphologyEx(src, dst, op, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_moveWindow(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_x = NULL;
    int x=0;
    PyObject* pyobj_y = NULL;
    int y=0;

    const char* keywords[] = { "winname", "x", "y", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:moveWindow", (char**)keywords, &pyobj_winname, &pyobj_x, &pyobj_y) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to(pyobj_y, y, ArgInfo("y", 0)) )
    {
        ERRWRAP2(cv::moveWindow(winname, x, y));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_mulSpectrums(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_a = NULL;
    Mat a;
    PyObject* pyobj_b = NULL;
    Mat b;
    PyObject* pyobj_c = NULL;
    Mat c;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;

    const char* keywords[] = { "a", "b", "flags", "c", "conjB", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:mulSpectrums", (char**)keywords, &pyobj_a, &pyobj_b, &pyobj_flags, &pyobj_c, &pyobj_conjB) &&
        pyopencv_to(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to(pyobj_b, b, ArgInfo("b", 0)) &&
        pyopencv_to(pyobj_c, c, ArgInfo("c", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_conjB, conjB, ArgInfo("conjB", 0)) )
    {
        ERRWRAP2(cv::mulSpectrums(a, b, c, flags, conjB));
        return pyopencv_from(c);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_a = NULL;
    UMat a;
    PyObject* pyobj_b = NULL;
    UMat b;
    PyObject* pyobj_c = NULL;
    UMat c;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;

    const char* keywords[] = { "a", "b", "flags", "c", "conjB", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:mulSpectrums", (char**)keywords, &pyobj_a, &pyobj_b, &pyobj_flags, &pyobj_c, &pyobj_conjB) &&
        pyopencv_to(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to(pyobj_b, b, ArgInfo("b", 0)) &&
        pyopencv_to(pyobj_c, c, ArgInfo("c", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_conjB, conjB, ArgInfo("conjB", 0)) )
    {
        ERRWRAP2(cv::mulSpectrums(a, b, c, flags, conjB));
        return pyopencv_from(c);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_mulTransposed(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_aTa = NULL;
    bool aTa=0;
    PyObject* pyobj_delta = NULL;
    Mat delta;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src", "aTa", "dst", "delta", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:mulTransposed", (char**)keywords, &pyobj_src, &pyobj_aTa, &pyobj_dst, &pyobj_delta, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_aTa, aTa, ArgInfo("aTa", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::mulTransposed(src, dst, aTa, delta, scale, dtype));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_aTa = NULL;
    bool aTa=0;
    PyObject* pyobj_delta = NULL;
    UMat delta;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src", "aTa", "dst", "delta", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:mulTransposed", (char**)keywords, &pyobj_src, &pyobj_aTa, &pyobj_dst, &pyobj_delta, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_aTa, aTa, ArgInfo("aTa", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::mulTransposed(src, dst, aTa, delta, scale, dtype));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_multiply(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:multiply", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::multiply(src1, src2, dst, scale, dtype));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:multiply", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::multiply(src1, src2, dst, scale, dtype));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_namedWindow(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_flags = NULL;
    int flags=WINDOW_AUTOSIZE;

    const char* keywords[] = { "winname", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:namedWindow", (char**)keywords, &pyobj_winname, &pyobj_flags) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::namedWindow(winname, flags));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_norm(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    double retval;

    const char* keywords[] = { "src1", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:norm", (char**)keywords, &pyobj_src1, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::norm(src1, normType, mask));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    double retval;

    const char* keywords[] = { "src1", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:norm", (char**)keywords, &pyobj_src1, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::norm(src1, normType, mask));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    double retval;

    const char* keywords[] = { "src1", "src2", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:norm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::norm(src1, src2, normType, mask));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    double retval;

    const char* keywords[] = { "src1", "src2", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:norm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::norm(src1, src2, normType, mask));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_normalize(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=1;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_norm_type = NULL;
    int norm_type=NORM_L2;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "dst", "alpha", "beta", "norm_type", "dtype", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOO:normalize", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_beta, &pyobj_norm_type, &pyobj_dtype, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to(pyobj_norm_type, norm_type, ArgInfo("norm_type", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::normalize(src, dst, alpha, beta, norm_type, dtype, mask));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=1;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_norm_type = NULL;
    int norm_type=NORM_L2;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "dst", "alpha", "beta", "norm_type", "dtype", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOOO:normalize", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_beta, &pyobj_norm_type, &pyobj_dtype, &pyobj_mask) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to(pyobj_norm_type, norm_type, ArgInfo("norm_type", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::normalize(src, dst, alpha, beta, norm_type, dtype, mask));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_patchNaNs(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_a = NULL;
    Mat a;
    PyObject* pyobj_val = NULL;
    double val=0;

    const char* keywords[] = { "a", "val", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:patchNaNs", (char**)keywords, &pyobj_a, &pyobj_val) &&
        pyopencv_to(pyobj_a, a, ArgInfo("a", 1)) &&
        pyopencv_to(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(cv::patchNaNs(a, val));
        return pyopencv_from(a);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_a = NULL;
    UMat a;
    PyObject* pyobj_val = NULL;
    double val=0;

    const char* keywords[] = { "a", "val", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:patchNaNs", (char**)keywords, &pyobj_a, &pyobj_val) &&
        pyopencv_to(pyobj_a, a, ArgInfo("a", 1)) &&
        pyopencv_to(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(cv::patchNaNs(a, val));
        return pyopencv_from(a);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_pencilSketch(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst1 = NULL;
    Mat dst1;
    PyObject* pyobj_dst2 = NULL;
    Mat dst2;
    PyObject* pyobj_sigma_s = NULL;
    float sigma_s=60;
    PyObject* pyobj_sigma_r = NULL;
    float sigma_r=0.07f;
    PyObject* pyobj_shade_factor = NULL;
    float shade_factor=0.02f;

    const char* keywords[] = { "src", "dst1", "dst2", "sigma_s", "sigma_r", "shade_factor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOO:pencilSketch", (char**)keywords, &pyobj_src, &pyobj_dst1, &pyobj_dst2, &pyobj_sigma_s, &pyobj_sigma_r, &pyobj_shade_factor) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst1, dst1, ArgInfo("dst1", 1)) &&
        pyopencv_to(pyobj_dst2, dst2, ArgInfo("dst2", 1)) &&
        pyopencv_to(pyobj_sigma_s, sigma_s, ArgInfo("sigma_s", 0)) &&
        pyopencv_to(pyobj_sigma_r, sigma_r, ArgInfo("sigma_r", 0)) &&
        pyopencv_to(pyobj_shade_factor, shade_factor, ArgInfo("shade_factor", 0)) )
    {
        ERRWRAP2(cv::pencilSketch(src, dst1, dst2, sigma_s, sigma_r, shade_factor));
        return Py_BuildValue("(NN)", pyopencv_from(dst1), pyopencv_from(dst2));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst1 = NULL;
    UMat dst1;
    PyObject* pyobj_dst2 = NULL;
    UMat dst2;
    PyObject* pyobj_sigma_s = NULL;
    float sigma_s=60;
    PyObject* pyobj_sigma_r = NULL;
    float sigma_r=0.07f;
    PyObject* pyobj_shade_factor = NULL;
    float shade_factor=0.02f;

    const char* keywords[] = { "src", "dst1", "dst2", "sigma_s", "sigma_r", "shade_factor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOO:pencilSketch", (char**)keywords, &pyobj_src, &pyobj_dst1, &pyobj_dst2, &pyobj_sigma_s, &pyobj_sigma_r, &pyobj_shade_factor) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst1, dst1, ArgInfo("dst1", 1)) &&
        pyopencv_to(pyobj_dst2, dst2, ArgInfo("dst2", 1)) &&
        pyopencv_to(pyobj_sigma_s, sigma_s, ArgInfo("sigma_s", 0)) &&
        pyopencv_to(pyobj_sigma_r, sigma_r, ArgInfo("sigma_r", 0)) &&
        pyopencv_to(pyobj_shade_factor, shade_factor, ArgInfo("shade_factor", 0)) )
    {
        ERRWRAP2(cv::pencilSketch(src, dst1, dst2, sigma_s, sigma_r, shade_factor));
        return Py_BuildValue("(NN)", pyopencv_from(dst1), pyopencv_from(dst2));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_perspectiveTransform(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "src", "m", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:perspectiveTransform", (char**)keywords, &pyobj_src, &pyobj_m, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::perspectiveTransform(src, dst, m));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_m = NULL;
    UMat m;

    const char* keywords[] = { "src", "m", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:perspectiveTransform", (char**)keywords, &pyobj_src, &pyobj_m, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::perspectiveTransform(src, dst, m));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_phase(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_angle = NULL;
    Mat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "x", "y", "angle", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:phase", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_angle, &pyobj_angleInDegrees) &&
        pyopencv_to(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::phase(x, y, angle, angleInDegrees));
        return pyopencv_from(angle);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_angle = NULL;
    UMat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "x", "y", "angle", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:phase", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_angle, &pyobj_angleInDegrees) &&
        pyopencv_to(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::phase(x, y, angle, angleInDegrees));
        return pyopencv_from(angle);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_phaseCorrelate(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_window = NULL;
    Mat window;
    double response;
    Point2d retval;

    const char* keywords[] = { "src1", "src2", "window", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:phaseCorrelate", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_window) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_window, window, ArgInfo("window", 0)) )
    {
        ERRWRAP2(retval = cv::phaseCorrelate(src1, src2, window, &response));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(response));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_window = NULL;
    UMat window;
    double response;
    Point2d retval;

    const char* keywords[] = { "src1", "src2", "window", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:phaseCorrelate", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_window) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_window, window, ArgInfo("window", 0)) )
    {
        ERRWRAP2(retval = cv::phaseCorrelate(src1, src2, window, &response));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(response));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_pointPolygonTest(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_contour = NULL;
    Mat contour;
    PyObject* pyobj_pt = NULL;
    Point2f pt;
    PyObject* pyobj_measureDist = NULL;
    bool measureDist=0;
    double retval;

    const char* keywords[] = { "contour", "pt", "measureDist", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:pointPolygonTest", (char**)keywords, &pyobj_contour, &pyobj_pt, &pyobj_measureDist) &&
        pyopencv_to(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to(pyobj_pt, pt, ArgInfo("pt", 0)) &&
        pyopencv_to(pyobj_measureDist, measureDist, ArgInfo("measureDist", 0)) )
    {
        ERRWRAP2(retval = cv::pointPolygonTest(contour, pt, measureDist));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_contour = NULL;
    UMat contour;
    PyObject* pyobj_pt = NULL;
    Point2f pt;
    PyObject* pyobj_measureDist = NULL;
    bool measureDist=0;
    double retval;

    const char* keywords[] = { "contour", "pt", "measureDist", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:pointPolygonTest", (char**)keywords, &pyobj_contour, &pyobj_pt, &pyobj_measureDist) &&
        pyopencv_to(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to(pyobj_pt, pt, ArgInfo("pt", 0)) &&
        pyopencv_to(pyobj_measureDist, measureDist, ArgInfo("measureDist", 0)) )
    {
        ERRWRAP2(retval = cv::pointPolygonTest(contour, pt, measureDist));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_polarToCart(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;
    PyObject* pyobj_angle = NULL;
    Mat angle;
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "magnitude", "angle", "x", "y", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:polarToCart", (char**)keywords, &pyobj_magnitude, &pyobj_angle, &pyobj_x, &pyobj_y, &pyobj_angleInDegrees) &&
        pyopencv_to(pyobj_magnitude, magnitude, ArgInfo("magnitude", 0)) &&
        pyopencv_to(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to(pyobj_x, x, ArgInfo("x", 1)) &&
        pyopencv_to(pyobj_y, y, ArgInfo("y", 1)) &&
        pyopencv_to(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::polarToCart(magnitude, angle, x, y, angleInDegrees));
        return Py_BuildValue("(NN)", pyopencv_from(x), pyopencv_from(y));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;
    PyObject* pyobj_angle = NULL;
    UMat angle;
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "magnitude", "angle", "x", "y", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:polarToCart", (char**)keywords, &pyobj_magnitude, &pyobj_angle, &pyobj_x, &pyobj_y, &pyobj_angleInDegrees) &&
        pyopencv_to(pyobj_magnitude, magnitude, ArgInfo("magnitude", 0)) &&
        pyopencv_to(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to(pyobj_x, x, ArgInfo("x", 1)) &&
        pyopencv_to(pyobj_y, y, ArgInfo("y", 1)) &&
        pyopencv_to(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::polarToCart(magnitude, angle, x, y, angleInDegrees));
        return Py_BuildValue("(NN)", pyopencv_from(x), pyopencv_from(y));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_polylines(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pts = NULL;
    vector_Mat pts;
    PyObject* pyobj_isClosed = NULL;
    bool isClosed=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pts", "isClosed", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:polylines", (char**)keywords, &pyobj_img, &pyobj_pts, &pyobj_isClosed, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_pts, pts, ArgInfo("pts", 0)) &&
        pyopencv_to(pyobj_isClosed, isClosed, ArgInfo("isClosed", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::polylines(img, pts, isClosed, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pts = NULL;
    vector_UMat pts;
    PyObject* pyobj_isClosed = NULL;
    bool isClosed=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pts", "isClosed", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:polylines", (char**)keywords, &pyobj_img, &pyobj_pts, &pyobj_isClosed, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_pts, pts, ArgInfo("pts", 0)) &&
        pyopencv_to(pyobj_isClosed, isClosed, ArgInfo("isClosed", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::polylines(img, pts, isClosed, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_pow(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_power = NULL;
    double power=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "power", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:pow", (char**)keywords, &pyobj_src, &pyobj_power, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_power, power, ArgInfo("power", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::pow(src, power, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_power = NULL;
    double power=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "power", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:pow", (char**)keywords, &pyobj_src, &pyobj_power, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_power, power, ArgInfo("power", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::pow(src, power, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_preCornerDetect(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:preCornerDetect", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::preCornerDetect(src, dst, ksize, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:preCornerDetect", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::preCornerDetect(src, dst, ksize, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_projectPoints(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    Mat objectPoints;
    PyObject* pyobj_rvec = NULL;
    Mat rvec;
    PyObject* pyobj_tvec = NULL;
    Mat tvec;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_imagePoints = NULL;
    Mat imagePoints;
    PyObject* pyobj_jacobian = NULL;
    Mat jacobian;
    PyObject* pyobj_aspectRatio = NULL;
    double aspectRatio=0;

    const char* keywords[] = { "objectPoints", "rvec", "tvec", "cameraMatrix", "distCoeffs", "imagePoints", "jacobian", "aspectRatio", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOO:projectPoints", (char**)keywords, &pyobj_objectPoints, &pyobj_rvec, &pyobj_tvec, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_imagePoints, &pyobj_jacobian, &pyobj_aspectRatio) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 0)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 1)) &&
        pyopencv_to(pyobj_jacobian, jacobian, ArgInfo("jacobian", 1)) &&
        pyopencv_to(pyobj_aspectRatio, aspectRatio, ArgInfo("aspectRatio", 0)) )
    {
        ERRWRAP2(cv::projectPoints(objectPoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints, jacobian, aspectRatio));
        return Py_BuildValue("(NN)", pyopencv_from(imagePoints), pyopencv_from(jacobian));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    UMat objectPoints;
    PyObject* pyobj_rvec = NULL;
    UMat rvec;
    PyObject* pyobj_tvec = NULL;
    UMat tvec;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_imagePoints = NULL;
    UMat imagePoints;
    PyObject* pyobj_jacobian = NULL;
    UMat jacobian;
    PyObject* pyobj_aspectRatio = NULL;
    double aspectRatio=0;

    const char* keywords[] = { "objectPoints", "rvec", "tvec", "cameraMatrix", "distCoeffs", "imagePoints", "jacobian", "aspectRatio", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOO:projectPoints", (char**)keywords, &pyobj_objectPoints, &pyobj_rvec, &pyobj_tvec, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_imagePoints, &pyobj_jacobian, &pyobj_aspectRatio) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 0)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 1)) &&
        pyopencv_to(pyobj_jacobian, jacobian, ArgInfo("jacobian", 1)) &&
        pyopencv_to(pyobj_aspectRatio, aspectRatio, ArgInfo("aspectRatio", 0)) )
    {
        ERRWRAP2(cv::projectPoints(objectPoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints, jacobian, aspectRatio));
        return Py_BuildValue("(NN)", pyopencv_from(imagePoints), pyopencv_from(jacobian));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_putText(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_text = NULL;
    String text;
    PyObject* pyobj_org = NULL;
    Point org;
    PyObject* pyobj_fontFace = NULL;
    int fontFace=0;
    PyObject* pyobj_fontScale = NULL;
    double fontScale=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_bottomLeftOrigin = NULL;
    bool bottomLeftOrigin=false;

    const char* keywords[] = { "img", "text", "org", "fontFace", "fontScale", "color", "thickness", "lineType", "bottomLeftOrigin", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OOO:putText", (char**)keywords, &pyobj_img, &pyobj_text, &pyobj_org, &pyobj_fontFace, &pyobj_fontScale, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_bottomLeftOrigin) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_text, text, ArgInfo("text", 0)) &&
        pyopencv_to(pyobj_org, org, ArgInfo("org", 0)) &&
        pyopencv_to(pyobj_fontFace, fontFace, ArgInfo("fontFace", 0)) &&
        pyopencv_to(pyobj_fontScale, fontScale, ArgInfo("fontScale", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_bottomLeftOrigin, bottomLeftOrigin, ArgInfo("bottomLeftOrigin", 0)) )
    {
        ERRWRAP2(cv::putText(img, text, org, fontFace, fontScale, color, thickness, lineType, bottomLeftOrigin));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_text = NULL;
    String text;
    PyObject* pyobj_org = NULL;
    Point org;
    PyObject* pyobj_fontFace = NULL;
    int fontFace=0;
    PyObject* pyobj_fontScale = NULL;
    double fontScale=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_bottomLeftOrigin = NULL;
    bool bottomLeftOrigin=false;

    const char* keywords[] = { "img", "text", "org", "fontFace", "fontScale", "color", "thickness", "lineType", "bottomLeftOrigin", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OOO:putText", (char**)keywords, &pyobj_img, &pyobj_text, &pyobj_org, &pyobj_fontFace, &pyobj_fontScale, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_bottomLeftOrigin) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_text, text, ArgInfo("text", 0)) &&
        pyopencv_to(pyobj_org, org, ArgInfo("org", 0)) &&
        pyopencv_to(pyobj_fontFace, fontFace, ArgInfo("fontFace", 0)) &&
        pyopencv_to(pyobj_fontScale, fontScale, ArgInfo("fontScale", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_bottomLeftOrigin, bottomLeftOrigin, ArgInfo("bottomLeftOrigin", 0)) )
    {
        ERRWRAP2(cv::putText(img, text, org, fontFace, fontScale, color, thickness, lineType, bottomLeftOrigin));
        return pyopencv_from(img);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_pyrDown(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dstsize = NULL;
    Size dstsize;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dst", "dstsize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:pyrDown", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_dstsize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dstsize, dstsize, ArgInfo("dstsize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::pyrDown(src, dst, dstsize, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dstsize = NULL;
    Size dstsize;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dst", "dstsize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:pyrDown", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_dstsize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dstsize, dstsize, ArgInfo("dstsize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::pyrDown(src, dst, dstsize, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_pyrMeanShiftFiltering(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_sp = NULL;
    double sp=0;
    PyObject* pyobj_sr = NULL;
    double sr=0;
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=1;
    PyObject* pyobj_termcrit = NULL;
    TermCriteria termcrit=TermCriteria(TermCriteria::MAX_ITER+TermCriteria::EPS,5,1);

    const char* keywords[] = { "src", "sp", "sr", "dst", "maxLevel", "termcrit", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:pyrMeanShiftFiltering", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_dst, &pyobj_maxLevel, &pyobj_termcrit) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to(pyobj_termcrit, termcrit, ArgInfo("termcrit", 0)) )
    {
        ERRWRAP2(cv::pyrMeanShiftFiltering(src, dst, sp, sr, maxLevel, termcrit));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_sp = NULL;
    double sp=0;
    PyObject* pyobj_sr = NULL;
    double sr=0;
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=1;
    PyObject* pyobj_termcrit = NULL;
    TermCriteria termcrit=TermCriteria(TermCriteria::MAX_ITER+TermCriteria::EPS,5,1);

    const char* keywords[] = { "src", "sp", "sr", "dst", "maxLevel", "termcrit", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:pyrMeanShiftFiltering", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_dst, &pyobj_maxLevel, &pyobj_termcrit) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to(pyobj_termcrit, termcrit, ArgInfo("termcrit", 0)) )
    {
        ERRWRAP2(cv::pyrMeanShiftFiltering(src, dst, sp, sr, maxLevel, termcrit));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_pyrUp(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dstsize = NULL;
    Size dstsize;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dst", "dstsize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:pyrUp", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_dstsize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dstsize, dstsize, ArgInfo("dstsize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::pyrUp(src, dst, dstsize, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dstsize = NULL;
    Size dstsize;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dst", "dstsize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:pyrUp", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_dstsize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dstsize, dstsize, ArgInfo("dstsize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::pyrUp(src, dst, dstsize, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_randShuffle(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_iterFactor = NULL;
    double iterFactor=1.;

    const char* keywords[] = { "dst", "iterFactor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:randShuffle", (char**)keywords, &pyobj_dst, &pyobj_iterFactor) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_iterFactor, iterFactor, ArgInfo("iterFactor", 0)) )
    {
        ERRWRAP2(cv::randShuffle(dst, iterFactor, 0));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_iterFactor = NULL;
    double iterFactor=1.;

    const char* keywords[] = { "dst", "iterFactor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:randShuffle", (char**)keywords, &pyobj_dst, &pyobj_iterFactor) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_iterFactor, iterFactor, ArgInfo("iterFactor", 0)) )
    {
        ERRWRAP2(cv::randShuffle(dst, iterFactor, 0));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_randn(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_stddev = NULL;
    Mat stddev;

    const char* keywords[] = { "dst", "mean", "stddev", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:randn", (char**)keywords, &pyobj_dst, &pyobj_mean, &pyobj_stddev) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to(pyobj_stddev, stddev, ArgInfo("stddev", 0)) )
    {
        ERRWRAP2(cv::randn(dst, mean, stddev));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_stddev = NULL;
    UMat stddev;

    const char* keywords[] = { "dst", "mean", "stddev", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:randn", (char**)keywords, &pyobj_dst, &pyobj_mean, &pyobj_stddev) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to(pyobj_stddev, stddev, ArgInfo("stddev", 0)) )
    {
        ERRWRAP2(cv::randn(dst, mean, stddev));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_randu(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_low = NULL;
    Mat low;
    PyObject* pyobj_high = NULL;
    Mat high;

    const char* keywords[] = { "dst", "low", "high", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:randu", (char**)keywords, &pyobj_dst, &pyobj_low, &pyobj_high) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_low, low, ArgInfo("low", 0)) &&
        pyopencv_to(pyobj_high, high, ArgInfo("high", 0)) )
    {
        ERRWRAP2(cv::randu(dst, low, high));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_low = NULL;
    UMat low;
    PyObject* pyobj_high = NULL;
    UMat high;

    const char* keywords[] = { "dst", "low", "high", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:randu", (char**)keywords, &pyobj_dst, &pyobj_low, &pyobj_high) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_low, low, ArgInfo("low", 0)) &&
        pyopencv_to(pyobj_high, high, ArgInfo("high", 0)) )
    {
        ERRWRAP2(cv::randu(dst, low, high));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_readOpticalFlow(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_path = NULL;
    String path;
    Mat retval;

    const char* keywords[] = { "path", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:readOpticalFlow", (char**)keywords, &pyobj_path) &&
        pyopencv_to(pyobj_path, path, ArgInfo("path", 0)) )
    {
        ERRWRAP2(retval = cv::readOpticalFlow(path));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_recoverPose(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_E = NULL;
    Mat E;
    PyObject* pyobj_points1 = NULL;
    Mat points1;
    PyObject* pyobj_points2 = NULL;
    Mat points2;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_t = NULL;
    Mat t;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    int retval;

    const char* keywords[] = { "E", "points1", "points2", "cameraMatrix", "R", "t", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:recoverPose", (char**)keywords, &pyobj_E, &pyobj_points1, &pyobj_points2, &pyobj_cameraMatrix, &pyobj_R, &pyobj_t, &pyobj_mask) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 0)) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_t, t, ArgInfo("t", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::recoverPose(E, points1, points2, cameraMatrix, R, t, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(R), pyopencv_from(t), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_E = NULL;
    UMat E;
    PyObject* pyobj_points1 = NULL;
    UMat points1;
    PyObject* pyobj_points2 = NULL;
    UMat points2;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_t = NULL;
    UMat t;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    int retval;

    const char* keywords[] = { "E", "points1", "points2", "cameraMatrix", "R", "t", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:recoverPose", (char**)keywords, &pyobj_E, &pyobj_points1, &pyobj_points2, &pyobj_cameraMatrix, &pyobj_R, &pyobj_t, &pyobj_mask) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 0)) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_t, t, ArgInfo("t", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::recoverPose(E, points1, points2, cameraMatrix, R, t, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(R), pyopencv_from(t), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_E = NULL;
    Mat E;
    PyObject* pyobj_points1 = NULL;
    Mat points1;
    PyObject* pyobj_points2 = NULL;
    Mat points2;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_t = NULL;
    Mat t;
    PyObject* pyobj_focal = NULL;
    double focal=1.0;
    PyObject* pyobj_pp = NULL;
    Point2d pp=Point2d(0, 0);
    PyObject* pyobj_mask = NULL;
    Mat mask;
    int retval;

    const char* keywords[] = { "E", "points1", "points2", "R", "t", "focal", "pp", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOOO:recoverPose", (char**)keywords, &pyobj_E, &pyobj_points1, &pyobj_points2, &pyobj_R, &pyobj_t, &pyobj_focal, &pyobj_pp, &pyobj_mask) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 0)) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_t, t, ArgInfo("t", 1)) &&
        pyopencv_to(pyobj_focal, focal, ArgInfo("focal", 0)) &&
        pyopencv_to(pyobj_pp, pp, ArgInfo("pp", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::recoverPose(E, points1, points2, R, t, focal, pp, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(R), pyopencv_from(t), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_E = NULL;
    UMat E;
    PyObject* pyobj_points1 = NULL;
    UMat points1;
    PyObject* pyobj_points2 = NULL;
    UMat points2;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_t = NULL;
    UMat t;
    PyObject* pyobj_focal = NULL;
    double focal=1.0;
    PyObject* pyobj_pp = NULL;
    Point2d pp=Point2d(0, 0);
    PyObject* pyobj_mask = NULL;
    UMat mask;
    int retval;

    const char* keywords[] = { "E", "points1", "points2", "R", "t", "focal", "pp", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOOO:recoverPose", (char**)keywords, &pyobj_E, &pyobj_points1, &pyobj_points2, &pyobj_R, &pyobj_t, &pyobj_focal, &pyobj_pp, &pyobj_mask) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 0)) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_t, t, ArgInfo("t", 1)) &&
        pyopencv_to(pyobj_focal, focal, ArgInfo("focal", 0)) &&
        pyopencv_to(pyobj_pp, pp, ArgInfo("pp", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) )
    {
        ERRWRAP2(retval = cv::recoverPose(E, points1, points2, R, t, focal, pp, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(R), pyopencv_from(t), pyopencv_from(mask));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_E = NULL;
    Mat E;
    PyObject* pyobj_points1 = NULL;
    Mat points1;
    PyObject* pyobj_points2 = NULL;
    Mat points2;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_t = NULL;
    Mat t;
    PyObject* pyobj_distanceThresh = NULL;
    double distanceThresh=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_triangulatedPoints = NULL;
    Mat triangulatedPoints;
    int retval;

    const char* keywords[] = { "E", "points1", "points2", "cameraMatrix", "distanceThresh", "R", "t", "mask", "triangulatedPoints", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOOO:recoverPose", (char**)keywords, &pyobj_E, &pyobj_points1, &pyobj_points2, &pyobj_cameraMatrix, &pyobj_distanceThresh, &pyobj_R, &pyobj_t, &pyobj_mask, &pyobj_triangulatedPoints) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 0)) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_t, t, ArgInfo("t", 1)) &&
        pyopencv_to(pyobj_distanceThresh, distanceThresh, ArgInfo("distanceThresh", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to(pyobj_triangulatedPoints, triangulatedPoints, ArgInfo("triangulatedPoints", 1)) )
    {
        ERRWRAP2(retval = cv::recoverPose(E, points1, points2, cameraMatrix, R, t, distanceThresh, mask, triangulatedPoints));
        return Py_BuildValue("(NNNNN)", pyopencv_from(retval), pyopencv_from(R), pyopencv_from(t), pyopencv_from(mask), pyopencv_from(triangulatedPoints));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_E = NULL;
    UMat E;
    PyObject* pyobj_points1 = NULL;
    UMat points1;
    PyObject* pyobj_points2 = NULL;
    UMat points2;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_t = NULL;
    UMat t;
    PyObject* pyobj_distanceThresh = NULL;
    double distanceThresh=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_triangulatedPoints = NULL;
    UMat triangulatedPoints;
    int retval;

    const char* keywords[] = { "E", "points1", "points2", "cameraMatrix", "distanceThresh", "R", "t", "mask", "triangulatedPoints", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOOO:recoverPose", (char**)keywords, &pyobj_E, &pyobj_points1, &pyobj_points2, &pyobj_cameraMatrix, &pyobj_distanceThresh, &pyobj_R, &pyobj_t, &pyobj_mask, &pyobj_triangulatedPoints) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 0)) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_t, t, ArgInfo("t", 1)) &&
        pyopencv_to(pyobj_distanceThresh, distanceThresh, ArgInfo("distanceThresh", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to(pyobj_triangulatedPoints, triangulatedPoints, ArgInfo("triangulatedPoints", 1)) )
    {
        ERRWRAP2(retval = cv::recoverPose(E, points1, points2, cameraMatrix, R, t, distanceThresh, mask, triangulatedPoints));
        return Py_BuildValue("(NNNNN)", pyopencv_from(retval), pyopencv_from(R), pyopencv_from(t), pyopencv_from(mask), pyopencv_from(triangulatedPoints));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_rectangle(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:rectangle", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::rectangle(img, pt1, pt2, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:rectangle", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::rectangle(img, pt1, pt2, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_rec = NULL;
    Rect rec;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "rec", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:rectangle", (char**)keywords, &pyobj_img, &pyobj_rec, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_rec, rec, ArgInfo("rec", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::rectangle(img, rec, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_rec = NULL;
    Rect rec;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "rec", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:rectangle", (char**)keywords, &pyobj_img, &pyobj_rec, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to(pyobj_rec, rec, ArgInfo("rec", 0)) &&
        pyopencv_to(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::rectangle(img, rec, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_rectify3Collinear(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_cameraMatrix1 = NULL;
    Mat cameraMatrix1;
    PyObject* pyobj_distCoeffs1 = NULL;
    Mat distCoeffs1;
    PyObject* pyobj_cameraMatrix2 = NULL;
    Mat cameraMatrix2;
    PyObject* pyobj_distCoeffs2 = NULL;
    Mat distCoeffs2;
    PyObject* pyobj_cameraMatrix3 = NULL;
    Mat cameraMatrix3;
    PyObject* pyobj_distCoeffs3 = NULL;
    Mat distCoeffs3;
    PyObject* pyobj_imgpt1 = NULL;
    vector_Mat imgpt1;
    PyObject* pyobj_imgpt3 = NULL;
    vector_Mat imgpt3;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R12 = NULL;
    Mat R12;
    PyObject* pyobj_T12 = NULL;
    Mat T12;
    PyObject* pyobj_R13 = NULL;
    Mat R13;
    PyObject* pyobj_T13 = NULL;
    Mat T13;
    PyObject* pyobj_R1 = NULL;
    Mat R1;
    PyObject* pyobj_R2 = NULL;
    Mat R2;
    PyObject* pyobj_R3 = NULL;
    Mat R3;
    PyObject* pyobj_P1 = NULL;
    Mat P1;
    PyObject* pyobj_P2 = NULL;
    Mat P2;
    PyObject* pyobj_P3 = NULL;
    Mat P3;
    PyObject* pyobj_Q = NULL;
    Mat Q;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_newImgSize = NULL;
    Size newImgSize;
    Rect roi1;
    Rect roi2;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    float retval;

    const char* keywords[] = { "cameraMatrix1", "distCoeffs1", "cameraMatrix2", "distCoeffs2", "cameraMatrix3", "distCoeffs3", "imgpt1", "imgpt3", "imageSize", "R12", "T12", "R13", "T13", "alpha", "newImgSize", "flags", "R1", "R2", "R3", "P1", "P2", "P3", "Q", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOOOOOOO|OOOOOOO:rectify3Collinear", (char**)keywords, &pyobj_cameraMatrix1, &pyobj_distCoeffs1, &pyobj_cameraMatrix2, &pyobj_distCoeffs2, &pyobj_cameraMatrix3, &pyobj_distCoeffs3, &pyobj_imgpt1, &pyobj_imgpt3, &pyobj_imageSize, &pyobj_R12, &pyobj_T12, &pyobj_R13, &pyobj_T13, &pyobj_alpha, &pyobj_newImgSize, &pyobj_flags, &pyobj_R1, &pyobj_R2, &pyobj_R3, &pyobj_P1, &pyobj_P2, &pyobj_P3, &pyobj_Q) &&
        pyopencv_to(pyobj_cameraMatrix1, cameraMatrix1, ArgInfo("cameraMatrix1", 0)) &&
        pyopencv_to(pyobj_distCoeffs1, distCoeffs1, ArgInfo("distCoeffs1", 0)) &&
        pyopencv_to(pyobj_cameraMatrix2, cameraMatrix2, ArgInfo("cameraMatrix2", 0)) &&
        pyopencv_to(pyobj_distCoeffs2, distCoeffs2, ArgInfo("distCoeffs2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix3, cameraMatrix3, ArgInfo("cameraMatrix3", 0)) &&
        pyopencv_to(pyobj_distCoeffs3, distCoeffs3, ArgInfo("distCoeffs3", 0)) &&
        pyopencv_to(pyobj_imgpt1, imgpt1, ArgInfo("imgpt1", 0)) &&
        pyopencv_to(pyobj_imgpt3, imgpt3, ArgInfo("imgpt3", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R12, R12, ArgInfo("R12", 0)) &&
        pyopencv_to(pyobj_T12, T12, ArgInfo("T12", 0)) &&
        pyopencv_to(pyobj_R13, R13, ArgInfo("R13", 0)) &&
        pyopencv_to(pyobj_T13, T13, ArgInfo("T13", 0)) &&
        pyopencv_to(pyobj_R1, R1, ArgInfo("R1", 1)) &&
        pyopencv_to(pyobj_R2, R2, ArgInfo("R2", 1)) &&
        pyopencv_to(pyobj_R3, R3, ArgInfo("R3", 1)) &&
        pyopencv_to(pyobj_P1, P1, ArgInfo("P1", 1)) &&
        pyopencv_to(pyobj_P2, P2, ArgInfo("P2", 1)) &&
        pyopencv_to(pyobj_P3, P3, ArgInfo("P3", 1)) &&
        pyopencv_to(pyobj_Q, Q, ArgInfo("Q", 1)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_newImgSize, newImgSize, ArgInfo("newImgSize", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::rectify3Collinear(cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, cameraMatrix3, distCoeffs3, imgpt1, imgpt3, imageSize, R12, T12, R13, T13, R1, R2, R3, P1, P2, P3, Q, alpha, newImgSize, &roi1, &roi2, flags));
        return Py_BuildValue("(NNNNNNNNNN)", pyopencv_from(retval), pyopencv_from(R1), pyopencv_from(R2), pyopencv_from(R3), pyopencv_from(P1), pyopencv_from(P2), pyopencv_from(P3), pyopencv_from(Q), pyopencv_from(roi1), pyopencv_from(roi2));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_cameraMatrix1 = NULL;
    UMat cameraMatrix1;
    PyObject* pyobj_distCoeffs1 = NULL;
    UMat distCoeffs1;
    PyObject* pyobj_cameraMatrix2 = NULL;
    UMat cameraMatrix2;
    PyObject* pyobj_distCoeffs2 = NULL;
    UMat distCoeffs2;
    PyObject* pyobj_cameraMatrix3 = NULL;
    UMat cameraMatrix3;
    PyObject* pyobj_distCoeffs3 = NULL;
    UMat distCoeffs3;
    PyObject* pyobj_imgpt1 = NULL;
    vector_UMat imgpt1;
    PyObject* pyobj_imgpt3 = NULL;
    vector_UMat imgpt3;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R12 = NULL;
    UMat R12;
    PyObject* pyobj_T12 = NULL;
    UMat T12;
    PyObject* pyobj_R13 = NULL;
    UMat R13;
    PyObject* pyobj_T13 = NULL;
    UMat T13;
    PyObject* pyobj_R1 = NULL;
    UMat R1;
    PyObject* pyobj_R2 = NULL;
    UMat R2;
    PyObject* pyobj_R3 = NULL;
    UMat R3;
    PyObject* pyobj_P1 = NULL;
    UMat P1;
    PyObject* pyobj_P2 = NULL;
    UMat P2;
    PyObject* pyobj_P3 = NULL;
    UMat P3;
    PyObject* pyobj_Q = NULL;
    UMat Q;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_newImgSize = NULL;
    Size newImgSize;
    Rect roi1;
    Rect roi2;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    float retval;

    const char* keywords[] = { "cameraMatrix1", "distCoeffs1", "cameraMatrix2", "distCoeffs2", "cameraMatrix3", "distCoeffs3", "imgpt1", "imgpt3", "imageSize", "R12", "T12", "R13", "T13", "alpha", "newImgSize", "flags", "R1", "R2", "R3", "P1", "P2", "P3", "Q", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOOOOOOO|OOOOOOO:rectify3Collinear", (char**)keywords, &pyobj_cameraMatrix1, &pyobj_distCoeffs1, &pyobj_cameraMatrix2, &pyobj_distCoeffs2, &pyobj_cameraMatrix3, &pyobj_distCoeffs3, &pyobj_imgpt1, &pyobj_imgpt3, &pyobj_imageSize, &pyobj_R12, &pyobj_T12, &pyobj_R13, &pyobj_T13, &pyobj_alpha, &pyobj_newImgSize, &pyobj_flags, &pyobj_R1, &pyobj_R2, &pyobj_R3, &pyobj_P1, &pyobj_P2, &pyobj_P3, &pyobj_Q) &&
        pyopencv_to(pyobj_cameraMatrix1, cameraMatrix1, ArgInfo("cameraMatrix1", 0)) &&
        pyopencv_to(pyobj_distCoeffs1, distCoeffs1, ArgInfo("distCoeffs1", 0)) &&
        pyopencv_to(pyobj_cameraMatrix2, cameraMatrix2, ArgInfo("cameraMatrix2", 0)) &&
        pyopencv_to(pyobj_distCoeffs2, distCoeffs2, ArgInfo("distCoeffs2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix3, cameraMatrix3, ArgInfo("cameraMatrix3", 0)) &&
        pyopencv_to(pyobj_distCoeffs3, distCoeffs3, ArgInfo("distCoeffs3", 0)) &&
        pyopencv_to(pyobj_imgpt1, imgpt1, ArgInfo("imgpt1", 0)) &&
        pyopencv_to(pyobj_imgpt3, imgpt3, ArgInfo("imgpt3", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R12, R12, ArgInfo("R12", 0)) &&
        pyopencv_to(pyobj_T12, T12, ArgInfo("T12", 0)) &&
        pyopencv_to(pyobj_R13, R13, ArgInfo("R13", 0)) &&
        pyopencv_to(pyobj_T13, T13, ArgInfo("T13", 0)) &&
        pyopencv_to(pyobj_R1, R1, ArgInfo("R1", 1)) &&
        pyopencv_to(pyobj_R2, R2, ArgInfo("R2", 1)) &&
        pyopencv_to(pyobj_R3, R3, ArgInfo("R3", 1)) &&
        pyopencv_to(pyobj_P1, P1, ArgInfo("P1", 1)) &&
        pyopencv_to(pyobj_P2, P2, ArgInfo("P2", 1)) &&
        pyopencv_to(pyobj_P3, P3, ArgInfo("P3", 1)) &&
        pyopencv_to(pyobj_Q, Q, ArgInfo("Q", 1)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_newImgSize, newImgSize, ArgInfo("newImgSize", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::rectify3Collinear(cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, cameraMatrix3, distCoeffs3, imgpt1, imgpt3, imageSize, R12, T12, R13, T13, R1, R2, R3, P1, P2, P3, Q, alpha, newImgSize, &roi1, &roi2, flags));
        return Py_BuildValue("(NNNNNNNNNN)", pyopencv_from(retval), pyopencv_from(R1), pyopencv_from(R2), pyopencv_from(R3), pyopencv_from(P1), pyopencv_from(P2), pyopencv_from(P3), pyopencv_from(Q), pyopencv_from(roi1), pyopencv_from(roi2));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_reduce(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dim = NULL;
    int dim=0;
    PyObject* pyobj_rtype = NULL;
    int rtype=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src", "dim", "rtype", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:reduce", (char**)keywords, &pyobj_src, &pyobj_dim, &pyobj_rtype, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dim, dim, ArgInfo("dim", 0)) &&
        pyopencv_to(pyobj_rtype, rtype, ArgInfo("rtype", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::reduce(src, dst, dim, rtype, dtype));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dim = NULL;
    int dim=0;
    PyObject* pyobj_rtype = NULL;
    int rtype=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src", "dim", "rtype", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:reduce", (char**)keywords, &pyobj_src, &pyobj_dim, &pyobj_rtype, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dim, dim, ArgInfo("dim", 0)) &&
        pyopencv_to(pyobj_rtype, rtype, ArgInfo("rtype", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::reduce(src, dst, dim, rtype, dtype));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_remap(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_map1 = NULL;
    Mat map1;
    PyObject* pyobj_map2 = NULL;
    Mat map2;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=0;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "map1", "map2", "interpolation", "dst", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:remap", (char**)keywords, &pyobj_src, &pyobj_map1, &pyobj_map2, &pyobj_interpolation, &pyobj_dst, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_map1, map1, ArgInfo("map1", 0)) &&
        pyopencv_to(pyobj_map2, map2, ArgInfo("map2", 0)) &&
        pyopencv_to(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::remap(src, dst, map1, map2, interpolation, borderMode, borderValue));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_map1 = NULL;
    UMat map1;
    PyObject* pyobj_map2 = NULL;
    UMat map2;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=0;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "map1", "map2", "interpolation", "dst", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:remap", (char**)keywords, &pyobj_src, &pyobj_map1, &pyobj_map2, &pyobj_interpolation, &pyobj_dst, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_map1, map1, ArgInfo("map1", 0)) &&
        pyopencv_to(pyobj_map2, map2, ArgInfo("map2", 0)) &&
        pyopencv_to(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::remap(src, dst, map1, map2, interpolation, borderMode, borderValue));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_repeat(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_ny = NULL;
    int ny=0;
    PyObject* pyobj_nx = NULL;
    int nx=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "ny", "nx", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:repeat", (char**)keywords, &pyobj_src, &pyobj_ny, &pyobj_nx, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_ny, ny, ArgInfo("ny", 0)) &&
        pyopencv_to(pyobj_nx, nx, ArgInfo("nx", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::repeat(src, ny, nx, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_ny = NULL;
    int ny=0;
    PyObject* pyobj_nx = NULL;
    int nx=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "ny", "nx", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:repeat", (char**)keywords, &pyobj_src, &pyobj_ny, &pyobj_nx, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_ny, ny, ArgInfo("ny", 0)) &&
        pyopencv_to(pyobj_nx, nx, ArgInfo("nx", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::repeat(src, ny, nx, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_reprojectImageTo3D(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_disparity = NULL;
    Mat disparity;
    PyObject* pyobj__3dImage = NULL;
    Mat _3dImage;
    PyObject* pyobj_Q = NULL;
    Mat Q;
    PyObject* pyobj_handleMissingValues = NULL;
    bool handleMissingValues=false;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=-1;

    const char* keywords[] = { "disparity", "Q", "_3dImage", "handleMissingValues", "ddepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:reprojectImageTo3D", (char**)keywords, &pyobj_disparity, &pyobj_Q, &pyobj__3dImage, &pyobj_handleMissingValues, &pyobj_ddepth) &&
        pyopencv_to(pyobj_disparity, disparity, ArgInfo("disparity", 0)) &&
        pyopencv_to(pyobj__3dImage, _3dImage, ArgInfo("_3dImage", 1)) &&
        pyopencv_to(pyobj_Q, Q, ArgInfo("Q", 0)) &&
        pyopencv_to(pyobj_handleMissingValues, handleMissingValues, ArgInfo("handleMissingValues", 0)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) )
    {
        ERRWRAP2(cv::reprojectImageTo3D(disparity, _3dImage, Q, handleMissingValues, ddepth));
        return pyopencv_from(_3dImage);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_disparity = NULL;
    UMat disparity;
    PyObject* pyobj__3dImage = NULL;
    UMat _3dImage;
    PyObject* pyobj_Q = NULL;
    UMat Q;
    PyObject* pyobj_handleMissingValues = NULL;
    bool handleMissingValues=false;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=-1;

    const char* keywords[] = { "disparity", "Q", "_3dImage", "handleMissingValues", "ddepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:reprojectImageTo3D", (char**)keywords, &pyobj_disparity, &pyobj_Q, &pyobj__3dImage, &pyobj_handleMissingValues, &pyobj_ddepth) &&
        pyopencv_to(pyobj_disparity, disparity, ArgInfo("disparity", 0)) &&
        pyopencv_to(pyobj__3dImage, _3dImage, ArgInfo("_3dImage", 1)) &&
        pyopencv_to(pyobj_Q, Q, ArgInfo("Q", 0)) &&
        pyopencv_to(pyobj_handleMissingValues, handleMissingValues, ArgInfo("handleMissingValues", 0)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) )
    {
        ERRWRAP2(cv::reprojectImageTo3D(disparity, _3dImage, Q, handleMissingValues, ddepth));
        return pyopencv_from(_3dImage);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_resize(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_fx = NULL;
    double fx=0;
    PyObject* pyobj_fy = NULL;
    double fy=0;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=INTER_LINEAR;

    const char* keywords[] = { "src", "dsize", "dst", "fx", "fy", "interpolation", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:resize", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_dst, &pyobj_fx, &pyobj_fy, &pyobj_interpolation) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to(pyobj_fx, fx, ArgInfo("fx", 0)) &&
        pyopencv_to(pyobj_fy, fy, ArgInfo("fy", 0)) &&
        pyopencv_to(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) )
    {
        ERRWRAP2(cv::resize(src, dst, dsize, fx, fy, interpolation));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_fx = NULL;
    double fx=0;
    PyObject* pyobj_fy = NULL;
    double fy=0;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=INTER_LINEAR;

    const char* keywords[] = { "src", "dsize", "dst", "fx", "fy", "interpolation", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:resize", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_dst, &pyobj_fx, &pyobj_fy, &pyobj_interpolation) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to(pyobj_fx, fx, ArgInfo("fx", 0)) &&
        pyopencv_to(pyobj_fy, fy, ArgInfo("fy", 0)) &&
        pyopencv_to(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) )
    {
        ERRWRAP2(cv::resize(src, dst, dsize, fx, fy, interpolation));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_resizeWindow(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_width = NULL;
    int width=0;
    PyObject* pyobj_height = NULL;
    int height=0;

    const char* keywords[] = { "winname", "width", "height", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:resizeWindow", (char**)keywords, &pyobj_winname, &pyobj_width, &pyobj_height) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_width, width, ArgInfo("width", 0)) &&
        pyopencv_to(pyobj_height, height, ArgInfo("height", 0)) )
    {
        ERRWRAP2(cv::resizeWindow(winname, width, height));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_size = NULL;
    Size size;

    const char* keywords[] = { "winname", "size", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:resizeWindow", (char**)keywords, &pyobj_winname, &pyobj_size) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) )
    {
        ERRWRAP2(cv::resizeWindow(winname, size));
        Py_RETURN_NONE;
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_rotate(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_rotateCode = NULL;
    int rotateCode=0;

    const char* keywords[] = { "src", "rotateCode", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:rotate", (char**)keywords, &pyobj_src, &pyobj_rotateCode, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_rotateCode, rotateCode, ArgInfo("rotateCode", 0)) )
    {
        ERRWRAP2(cv::rotate(src, dst, rotateCode));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_rotateCode = NULL;
    int rotateCode=0;

    const char* keywords[] = { "src", "rotateCode", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:rotate", (char**)keywords, &pyobj_src, &pyobj_rotateCode, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_rotateCode, rotateCode, ArgInfo("rotateCode", 0)) )
    {
        ERRWRAP2(cv::rotate(src, dst, rotateCode));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_rotatedRectangleIntersection(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_rect1 = NULL;
    RotatedRect rect1;
    PyObject* pyobj_rect2 = NULL;
    RotatedRect rect2;
    PyObject* pyobj_intersectingRegion = NULL;
    Mat intersectingRegion;
    int retval;

    const char* keywords[] = { "rect1", "rect2", "intersectingRegion", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:rotatedRectangleIntersection", (char**)keywords, &pyobj_rect1, &pyobj_rect2, &pyobj_intersectingRegion) &&
        pyopencv_to(pyobj_rect1, rect1, ArgInfo("rect1", 0)) &&
        pyopencv_to(pyobj_rect2, rect2, ArgInfo("rect2", 0)) &&
        pyopencv_to(pyobj_intersectingRegion, intersectingRegion, ArgInfo("intersectingRegion", 1)) )
    {
        ERRWRAP2(retval = cv::rotatedRectangleIntersection(rect1, rect2, intersectingRegion));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(intersectingRegion));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_rect1 = NULL;
    RotatedRect rect1;
    PyObject* pyobj_rect2 = NULL;
    RotatedRect rect2;
    PyObject* pyobj_intersectingRegion = NULL;
    UMat intersectingRegion;
    int retval;

    const char* keywords[] = { "rect1", "rect2", "intersectingRegion", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:rotatedRectangleIntersection", (char**)keywords, &pyobj_rect1, &pyobj_rect2, &pyobj_intersectingRegion) &&
        pyopencv_to(pyobj_rect1, rect1, ArgInfo("rect1", 0)) &&
        pyopencv_to(pyobj_rect2, rect2, ArgInfo("rect2", 0)) &&
        pyopencv_to(pyobj_intersectingRegion, intersectingRegion, ArgInfo("intersectingRegion", 1)) )
    {
        ERRWRAP2(retval = cv::rotatedRectangleIntersection(rect1, rect2, intersectingRegion));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(intersectingRegion));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_sampsonDistance(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_pt1 = NULL;
    Mat pt1;
    PyObject* pyobj_pt2 = NULL;
    Mat pt2;
    PyObject* pyobj_F = NULL;
    Mat F;
    double retval;

    const char* keywords[] = { "pt1", "pt2", "F", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:sampsonDistance", (char**)keywords, &pyobj_pt1, &pyobj_pt2, &pyobj_F) &&
        pyopencv_to(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 0)) )
    {
        ERRWRAP2(retval = cv::sampsonDistance(pt1, pt2, F));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_pt1 = NULL;
    UMat pt1;
    PyObject* pyobj_pt2 = NULL;
    UMat pt2;
    PyObject* pyobj_F = NULL;
    UMat F;
    double retval;

    const char* keywords[] = { "pt1", "pt2", "F", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:sampsonDistance", (char**)keywords, &pyobj_pt1, &pyobj_pt2, &pyobj_F) &&
        pyopencv_to(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 0)) )
    {
        ERRWRAP2(retval = cv::sampsonDistance(pt1, pt2, F));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_scaleAdd(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src1", "alpha", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:scaleAdd", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::scaleAdd(src1, alpha, src2, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src1", "alpha", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:scaleAdd", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::scaleAdd(src1, alpha, src2, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_seamlessClone(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_p = NULL;
    Point p;
    PyObject* pyobj_blend = NULL;
    Mat blend;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dst", "mask", "p", "flags", "blend", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|O:seamlessClone", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_p, &pyobj_flags, &pyobj_blend) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_p, p, ArgInfo("p", 0)) &&
        pyopencv_to(pyobj_blend, blend, ArgInfo("blend", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::seamlessClone(src, dst, mask, p, blend, flags));
        return pyopencv_from(blend);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_p = NULL;
    Point p;
    PyObject* pyobj_blend = NULL;
    UMat blend;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dst", "mask", "p", "flags", "blend", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|O:seamlessClone", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_p, &pyobj_flags, &pyobj_blend) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_p, p, ArgInfo("p", 0)) &&
        pyopencv_to(pyobj_blend, blend, ArgInfo("blend", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::seamlessClone(src, dst, mask, p, blend, flags));
        return pyopencv_from(blend);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_selectROI(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_windowName = NULL;
    String windowName;
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_showCrosshair = NULL;
    bool showCrosshair=true;
    PyObject* pyobj_fromCenter = NULL;
    bool fromCenter=false;
    Rect retval;

    const char* keywords[] = { "windowName", "img", "showCrosshair", "fromCenter", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:selectROI", (char**)keywords, &pyobj_windowName, &pyobj_img, &pyobj_showCrosshair, &pyobj_fromCenter) &&
        pyopencv_to(pyobj_windowName, windowName, ArgInfo("windowName", 0)) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_showCrosshair, showCrosshair, ArgInfo("showCrosshair", 0)) &&
        pyopencv_to(pyobj_fromCenter, fromCenter, ArgInfo("fromCenter", 0)) )
    {
        ERRWRAP2(retval = cv::selectROI(windowName, img, showCrosshair, fromCenter));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_windowName = NULL;
    String windowName;
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_showCrosshair = NULL;
    bool showCrosshair=true;
    PyObject* pyobj_fromCenter = NULL;
    bool fromCenter=false;
    Rect retval;

    const char* keywords[] = { "windowName", "img", "showCrosshair", "fromCenter", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:selectROI", (char**)keywords, &pyobj_windowName, &pyobj_img, &pyobj_showCrosshair, &pyobj_fromCenter) &&
        pyopencv_to(pyobj_windowName, windowName, ArgInfo("windowName", 0)) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_showCrosshair, showCrosshair, ArgInfo("showCrosshair", 0)) &&
        pyopencv_to(pyobj_fromCenter, fromCenter, ArgInfo("fromCenter", 0)) )
    {
        ERRWRAP2(retval = cv::selectROI(windowName, img, showCrosshair, fromCenter));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_showCrosshair = NULL;
    bool showCrosshair=true;
    PyObject* pyobj_fromCenter = NULL;
    bool fromCenter=false;
    Rect retval;

    const char* keywords[] = { "img", "showCrosshair", "fromCenter", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:selectROI", (char**)keywords, &pyobj_img, &pyobj_showCrosshair, &pyobj_fromCenter) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_showCrosshair, showCrosshair, ArgInfo("showCrosshair", 0)) &&
        pyopencv_to(pyobj_fromCenter, fromCenter, ArgInfo("fromCenter", 0)) )
    {
        ERRWRAP2(retval = cv::selectROI(img, showCrosshair, fromCenter));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_showCrosshair = NULL;
    bool showCrosshair=true;
    PyObject* pyobj_fromCenter = NULL;
    bool fromCenter=false;
    Rect retval;

    const char* keywords[] = { "img", "showCrosshair", "fromCenter", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:selectROI", (char**)keywords, &pyobj_img, &pyobj_showCrosshair, &pyobj_fromCenter) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_showCrosshair, showCrosshair, ArgInfo("showCrosshair", 0)) &&
        pyopencv_to(pyobj_fromCenter, fromCenter, ArgInfo("fromCenter", 0)) )
    {
        ERRWRAP2(retval = cv::selectROI(img, showCrosshair, fromCenter));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_selectROIs(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_windowName = NULL;
    String windowName;
    PyObject* pyobj_img = NULL;
    Mat img;
    vector_Rect boundingBoxes;
    PyObject* pyobj_showCrosshair = NULL;
    bool showCrosshair=true;
    PyObject* pyobj_fromCenter = NULL;
    bool fromCenter=false;

    const char* keywords[] = { "windowName", "img", "showCrosshair", "fromCenter", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:selectROIs", (char**)keywords, &pyobj_windowName, &pyobj_img, &pyobj_showCrosshair, &pyobj_fromCenter) &&
        pyopencv_to(pyobj_windowName, windowName, ArgInfo("windowName", 0)) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_showCrosshair, showCrosshair, ArgInfo("showCrosshair", 0)) &&
        pyopencv_to(pyobj_fromCenter, fromCenter, ArgInfo("fromCenter", 0)) )
    {
        ERRWRAP2(cv::selectROIs(windowName, img, boundingBoxes, showCrosshair, fromCenter));
        return pyopencv_from(boundingBoxes);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_windowName = NULL;
    String windowName;
    PyObject* pyobj_img = NULL;
    UMat img;
    vector_Rect boundingBoxes;
    PyObject* pyobj_showCrosshair = NULL;
    bool showCrosshair=true;
    PyObject* pyobj_fromCenter = NULL;
    bool fromCenter=false;

    const char* keywords[] = { "windowName", "img", "showCrosshair", "fromCenter", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:selectROIs", (char**)keywords, &pyobj_windowName, &pyobj_img, &pyobj_showCrosshair, &pyobj_fromCenter) &&
        pyopencv_to(pyobj_windowName, windowName, ArgInfo("windowName", 0)) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_showCrosshair, showCrosshair, ArgInfo("showCrosshair", 0)) &&
        pyopencv_to(pyobj_fromCenter, fromCenter, ArgInfo("fromCenter", 0)) )
    {
        ERRWRAP2(cv::selectROIs(windowName, img, boundingBoxes, showCrosshair, fromCenter));
        return pyopencv_from(boundingBoxes);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_sepFilter2D(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_kernelX = NULL;
    Mat kernelX;
    PyObject* pyobj_kernelY = NULL;
    Mat kernelY;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "kernelX", "kernelY", "dst", "anchor", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:sepFilter2D", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_kernelX, &pyobj_kernelY, &pyobj_dst, &pyobj_anchor, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_kernelX, kernelX, ArgInfo("kernelX", 0)) &&
        pyopencv_to(pyobj_kernelY, kernelY, ArgInfo("kernelY", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::sepFilter2D(src, dst, ddepth, kernelX, kernelY, anchor, delta, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_kernelX = NULL;
    UMat kernelX;
    PyObject* pyobj_kernelY = NULL;
    UMat kernelY;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "kernelX", "kernelY", "dst", "anchor", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:sepFilter2D", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_kernelX, &pyobj_kernelY, &pyobj_dst, &pyobj_anchor, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_kernelX, kernelX, ArgInfo("kernelX", 0)) &&
        pyopencv_to(pyobj_kernelY, kernelY, ArgInfo("kernelY", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::sepFilter2D(src, dst, ddepth, kernelX, kernelY, anchor, delta, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_setIdentity(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_mtx = NULL;
    Mat mtx;
    PyObject* pyobj_s = NULL;
    Scalar s=Scalar(1);

    const char* keywords[] = { "mtx", "s", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:setIdentity", (char**)keywords, &pyobj_mtx, &pyobj_s) &&
        pyopencv_to(pyobj_mtx, mtx, ArgInfo("mtx", 1)) &&
        pyopencv_to(pyobj_s, s, ArgInfo("s", 0)) )
    {
        ERRWRAP2(cv::setIdentity(mtx, s));
        return pyopencv_from(mtx);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_mtx = NULL;
    UMat mtx;
    PyObject* pyobj_s = NULL;
    Scalar s=Scalar(1);

    const char* keywords[] = { "mtx", "s", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:setIdentity", (char**)keywords, &pyobj_mtx, &pyobj_s) &&
        pyopencv_to(pyobj_mtx, mtx, ArgInfo("mtx", 1)) &&
        pyopencv_to(pyobj_s, s, ArgInfo("s", 0)) )
    {
        ERRWRAP2(cv::setIdentity(mtx, s));
        return pyopencv_from(mtx);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_setNumThreads(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_nthreads = NULL;
    int nthreads=0;

    const char* keywords[] = { "nthreads", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:setNumThreads", (char**)keywords, &pyobj_nthreads) &&
        pyopencv_to(pyobj_nthreads, nthreads, ArgInfo("nthreads", 0)) )
    {
        ERRWRAP2(cv::setNumThreads(nthreads));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setRNGSeed(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_seed = NULL;
    int seed=0;

    const char* keywords[] = { "seed", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:setRNGSeed", (char**)keywords, &pyobj_seed) &&
        pyopencv_to(pyobj_seed, seed, ArgInfo("seed", 0)) )
    {
        ERRWRAP2(cv::setRNGSeed(seed));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setTrackbarMax(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_trackbarname = NULL;
    String trackbarname;
    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_maxval = NULL;
    int maxval=0;

    const char* keywords[] = { "trackbarname", "winname", "maxval", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:setTrackbarMax", (char**)keywords, &pyobj_trackbarname, &pyobj_winname, &pyobj_maxval) &&
        pyopencv_to(pyobj_trackbarname, trackbarname, ArgInfo("trackbarname", 0)) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_maxval, maxval, ArgInfo("maxval", 0)) )
    {
        ERRWRAP2(cv::setTrackbarMax(trackbarname, winname, maxval));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setTrackbarMin(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_trackbarname = NULL;
    String trackbarname;
    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_minval = NULL;
    int minval=0;

    const char* keywords[] = { "trackbarname", "winname", "minval", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:setTrackbarMin", (char**)keywords, &pyobj_trackbarname, &pyobj_winname, &pyobj_minval) &&
        pyopencv_to(pyobj_trackbarname, trackbarname, ArgInfo("trackbarname", 0)) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_minval, minval, ArgInfo("minval", 0)) )
    {
        ERRWRAP2(cv::setTrackbarMin(trackbarname, winname, minval));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setTrackbarPos(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_trackbarname = NULL;
    String trackbarname;
    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_pos = NULL;
    int pos=0;

    const char* keywords[] = { "trackbarname", "winname", "pos", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:setTrackbarPos", (char**)keywords, &pyobj_trackbarname, &pyobj_winname, &pyobj_pos) &&
        pyopencv_to(pyobj_trackbarname, trackbarname, ArgInfo("trackbarname", 0)) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_pos, pos, ArgInfo("pos", 0)) )
    {
        ERRWRAP2(cv::setTrackbarPos(trackbarname, winname, pos));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setUseOpenVX(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_flag = NULL;
    bool flag=0;

    const char* keywords[] = { "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:setUseOpenVX", (char**)keywords, &pyobj_flag) &&
        pyopencv_to(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(cv::setUseOpenVX(flag));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setUseOptimized(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_onoff = NULL;
    bool onoff=0;

    const char* keywords[] = { "onoff", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:setUseOptimized", (char**)keywords, &pyobj_onoff) &&
        pyopencv_to(pyobj_onoff, onoff, ArgInfo("onoff", 0)) )
    {
        ERRWRAP2(cv::setUseOptimized(onoff));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setWindowProperty(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_prop_id = NULL;
    int prop_id=0;
    PyObject* pyobj_prop_value = NULL;
    double prop_value=0;

    const char* keywords[] = { "winname", "prop_id", "prop_value", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:setWindowProperty", (char**)keywords, &pyobj_winname, &pyobj_prop_id, &pyobj_prop_value) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_prop_id, prop_id, ArgInfo("prop_id", 0)) &&
        pyopencv_to(pyobj_prop_value, prop_value, ArgInfo("prop_value", 0)) )
    {
        ERRWRAP2(cv::setWindowProperty(winname, prop_id, prop_value));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setWindowTitle(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_title = NULL;
    String title;

    const char* keywords[] = { "winname", "title", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:setWindowTitle", (char**)keywords, &pyobj_winname, &pyobj_title) &&
        pyopencv_to(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to(pyobj_title, title, ArgInfo("title", 0)) )
    {
        ERRWRAP2(cv::setWindowTitle(winname, title));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_solve(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=DECOMP_LU;
    bool retval;

    const char* keywords[] = { "src1", "src2", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:solve", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::solve(src1, src2, dst, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=DECOMP_LU;
    bool retval;

    const char* keywords[] = { "src1", "src2", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OO:solve", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::solve(src1, src2, dst, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_solveCubic(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_coeffs = NULL;
    Mat coeffs;
    PyObject* pyobj_roots = NULL;
    Mat roots;
    int retval;

    const char* keywords[] = { "coeffs", "roots", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:solveCubic", (char**)keywords, &pyobj_coeffs, &pyobj_roots) &&
        pyopencv_to(pyobj_coeffs, coeffs, ArgInfo("coeffs", 0)) &&
        pyopencv_to(pyobj_roots, roots, ArgInfo("roots", 1)) )
    {
        ERRWRAP2(retval = cv::solveCubic(coeffs, roots));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(roots));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_coeffs = NULL;
    UMat coeffs;
    PyObject* pyobj_roots = NULL;
    UMat roots;
    int retval;

    const char* keywords[] = { "coeffs", "roots", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:solveCubic", (char**)keywords, &pyobj_coeffs, &pyobj_roots) &&
        pyopencv_to(pyobj_coeffs, coeffs, ArgInfo("coeffs", 0)) &&
        pyopencv_to(pyobj_roots, roots, ArgInfo("roots", 1)) )
    {
        ERRWRAP2(retval = cv::solveCubic(coeffs, roots));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(roots));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_solveLP(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_Func = NULL;
    Mat Func;
    PyObject* pyobj_Constr = NULL;
    Mat Constr;
    PyObject* pyobj_z = NULL;
    Mat z;
    int retval;

    const char* keywords[] = { "Func", "Constr", "z", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:solveLP", (char**)keywords, &pyobj_Func, &pyobj_Constr, &pyobj_z) &&
        pyopencv_to(pyobj_Func, Func, ArgInfo("Func", 0)) &&
        pyopencv_to(pyobj_Constr, Constr, ArgInfo("Constr", 0)) &&
        pyopencv_to(pyobj_z, z, ArgInfo("z", 1)) )
    {
        ERRWRAP2(retval = cv::solveLP(Func, Constr, z));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(z));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_Func = NULL;
    UMat Func;
    PyObject* pyobj_Constr = NULL;
    UMat Constr;
    PyObject* pyobj_z = NULL;
    UMat z;
    int retval;

    const char* keywords[] = { "Func", "Constr", "z", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:solveLP", (char**)keywords, &pyobj_Func, &pyobj_Constr, &pyobj_z) &&
        pyopencv_to(pyobj_Func, Func, ArgInfo("Func", 0)) &&
        pyopencv_to(pyobj_Constr, Constr, ArgInfo("Constr", 0)) &&
        pyopencv_to(pyobj_z, z, ArgInfo("z", 1)) )
    {
        ERRWRAP2(retval = cv::solveLP(Func, Constr, z));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(z));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_solveP3P(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    Mat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_Mat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_Mat tvecs;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    int retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "flags", "rvecs", "tvecs", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OO:solveP3P", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_flags, &pyobj_rvecs, &pyobj_tvecs) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::solveP3P(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, flags));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(rvecs), pyopencv_from(tvecs));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    UMat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_UMat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_UMat tvecs;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    int retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "flags", "rvecs", "tvecs", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OO:solveP3P", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_flags, &pyobj_rvecs, &pyobj_tvecs) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::solveP3P(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, flags));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(rvecs), pyopencv_from(tvecs));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_solvePnP(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    Mat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvec = NULL;
    Mat rvec;
    PyObject* pyobj_tvec = NULL;
    Mat tvec;
    PyObject* pyobj_useExtrinsicGuess = NULL;
    bool useExtrinsicGuess=false;
    PyObject* pyobj_flags = NULL;
    int flags=SOLVEPNP_ITERATIVE;
    bool retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "rvec", "tvec", "useExtrinsicGuess", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:solvePnP", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvec, &pyobj_tvec, &pyobj_useExtrinsicGuess, &pyobj_flags) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 1)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 1)) &&
        pyopencv_to(pyobj_useExtrinsicGuess, useExtrinsicGuess, ArgInfo("useExtrinsicGuess", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, useExtrinsicGuess, flags));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(rvec), pyopencv_from(tvec));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    UMat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvec = NULL;
    UMat rvec;
    PyObject* pyobj_tvec = NULL;
    UMat tvec;
    PyObject* pyobj_useExtrinsicGuess = NULL;
    bool useExtrinsicGuess=false;
    PyObject* pyobj_flags = NULL;
    int flags=SOLVEPNP_ITERATIVE;
    bool retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "rvec", "tvec", "useExtrinsicGuess", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:solvePnP", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvec, &pyobj_tvec, &pyobj_useExtrinsicGuess, &pyobj_flags) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 1)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 1)) &&
        pyopencv_to(pyobj_useExtrinsicGuess, useExtrinsicGuess, ArgInfo("useExtrinsicGuess", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, useExtrinsicGuess, flags));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(rvec), pyopencv_from(tvec));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_solvePnPGeneric(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    Mat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_Mat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_Mat tvecs;
    PyObject* pyobj_useExtrinsicGuess = NULL;
    bool useExtrinsicGuess=false;
    PyObject* pyobj_flags = NULL;
    SolvePnPMethod flags=SOLVEPNP_ITERATIVE;
    PyObject* pyobj_rvec = NULL;
    Mat rvec;
    PyObject* pyobj_tvec = NULL;
    Mat tvec;
    PyObject* pyobj_reprojectionError = NULL;
    Mat reprojectionError;
    int retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "rvecs", "tvecs", "useExtrinsicGuess", "flags", "rvec", "tvec", "reprojectionError", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOOOO:solvePnPGeneric", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvecs, &pyobj_tvecs, &pyobj_useExtrinsicGuess, &pyobj_flags, &pyobj_rvec, &pyobj_tvec, &pyobj_reprojectionError) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_useExtrinsicGuess, useExtrinsicGuess, ArgInfo("useExtrinsicGuess", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 0)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 0)) &&
        pyopencv_to(pyobj_reprojectionError, reprojectionError, ArgInfo("reprojectionError", 1)) )
    {
        ERRWRAP2(retval = cv::solvePnPGeneric(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, useExtrinsicGuess, flags, rvec, tvec, reprojectionError));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(rvecs), pyopencv_from(tvecs), pyopencv_from(reprojectionError));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    UMat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvecs = NULL;
    vector_UMat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_UMat tvecs;
    PyObject* pyobj_useExtrinsicGuess = NULL;
    bool useExtrinsicGuess=false;
    PyObject* pyobj_flags = NULL;
    SolvePnPMethod flags=SOLVEPNP_ITERATIVE;
    PyObject* pyobj_rvec = NULL;
    UMat rvec;
    PyObject* pyobj_tvec = NULL;
    UMat tvec;
    PyObject* pyobj_reprojectionError = NULL;
    UMat reprojectionError;
    int retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "rvecs", "tvecs", "useExtrinsicGuess", "flags", "rvec", "tvec", "reprojectionError", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOOOO:solvePnPGeneric", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvecs, &pyobj_tvecs, &pyobj_useExtrinsicGuess, &pyobj_flags, &pyobj_rvec, &pyobj_tvec, &pyobj_reprojectionError) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_useExtrinsicGuess, useExtrinsicGuess, ArgInfo("useExtrinsicGuess", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 0)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 0)) &&
        pyopencv_to(pyobj_reprojectionError, reprojectionError, ArgInfo("reprojectionError", 1)) )
    {
        ERRWRAP2(retval = cv::solvePnPGeneric(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, useExtrinsicGuess, flags, rvec, tvec, reprojectionError));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(rvecs), pyopencv_from(tvecs), pyopencv_from(reprojectionError));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_solvePnPRansac(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    Mat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvec = NULL;
    Mat rvec;
    PyObject* pyobj_tvec = NULL;
    Mat tvec;
    PyObject* pyobj_useExtrinsicGuess = NULL;
    bool useExtrinsicGuess=false;
    PyObject* pyobj_iterationsCount = NULL;
    int iterationsCount=100;
    PyObject* pyobj_reprojectionError = NULL;
    float reprojectionError=8.0;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.99;
    PyObject* pyobj_inliers = NULL;
    Mat inliers;
    PyObject* pyobj_flags = NULL;
    int flags=SOLVEPNP_ITERATIVE;
    bool retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "rvec", "tvec", "useExtrinsicGuess", "iterationsCount", "reprojectionError", "confidence", "inliers", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOOOOO:solvePnPRansac", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvec, &pyobj_tvec, &pyobj_useExtrinsicGuess, &pyobj_iterationsCount, &pyobj_reprojectionError, &pyobj_confidence, &pyobj_inliers, &pyobj_flags) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 1)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 1)) &&
        pyopencv_to(pyobj_useExtrinsicGuess, useExtrinsicGuess, ArgInfo("useExtrinsicGuess", 0)) &&
        pyopencv_to(pyobj_iterationsCount, iterationsCount, ArgInfo("iterationsCount", 0)) &&
        pyopencv_to(pyobj_reprojectionError, reprojectionError, ArgInfo("reprojectionError", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) &&
        pyopencv_to(pyobj_inliers, inliers, ArgInfo("inliers", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::solvePnPRansac(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, useExtrinsicGuess, iterationsCount, reprojectionError, confidence, inliers, flags));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(rvec), pyopencv_from(tvec), pyopencv_from(inliers));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    UMat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvec = NULL;
    UMat rvec;
    PyObject* pyobj_tvec = NULL;
    UMat tvec;
    PyObject* pyobj_useExtrinsicGuess = NULL;
    bool useExtrinsicGuess=false;
    PyObject* pyobj_iterationsCount = NULL;
    int iterationsCount=100;
    PyObject* pyobj_reprojectionError = NULL;
    float reprojectionError=8.0;
    PyObject* pyobj_confidence = NULL;
    double confidence=0.99;
    PyObject* pyobj_inliers = NULL;
    UMat inliers;
    PyObject* pyobj_flags = NULL;
    int flags=SOLVEPNP_ITERATIVE;
    bool retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "rvec", "tvec", "useExtrinsicGuess", "iterationsCount", "reprojectionError", "confidence", "inliers", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOOOOOO:solvePnPRansac", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvec, &pyobj_tvec, &pyobj_useExtrinsicGuess, &pyobj_iterationsCount, &pyobj_reprojectionError, &pyobj_confidence, &pyobj_inliers, &pyobj_flags) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 1)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 1)) &&
        pyopencv_to(pyobj_useExtrinsicGuess, useExtrinsicGuess, ArgInfo("useExtrinsicGuess", 0)) &&
        pyopencv_to(pyobj_iterationsCount, iterationsCount, ArgInfo("iterationsCount", 0)) &&
        pyopencv_to(pyobj_reprojectionError, reprojectionError, ArgInfo("reprojectionError", 0)) &&
        pyopencv_to(pyobj_confidence, confidence, ArgInfo("confidence", 0)) &&
        pyopencv_to(pyobj_inliers, inliers, ArgInfo("inliers", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::solvePnPRansac(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, useExtrinsicGuess, iterationsCount, reprojectionError, confidence, inliers, flags));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(rvec), pyopencv_from(tvec), pyopencv_from(inliers));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_solvePnPRefineLM(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    Mat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvec = NULL;
    Mat rvec;
    PyObject* pyobj_tvec = NULL;
    Mat tvec;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 20, FLT_EPSILON);

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "rvec", "tvec", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:solvePnPRefineLM", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvec, &pyobj_tvec, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 1)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 1)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(cv::solvePnPRefineLM(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, criteria));
        return Py_BuildValue("(NN)", pyopencv_from(rvec), pyopencv_from(tvec));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    UMat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvec = NULL;
    UMat rvec;
    PyObject* pyobj_tvec = NULL;
    UMat tvec;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 20, FLT_EPSILON);

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "rvec", "tvec", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:solvePnPRefineLM", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvec, &pyobj_tvec, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 1)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 1)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(cv::solvePnPRefineLM(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, criteria));
        return Py_BuildValue("(NN)", pyopencv_from(rvec), pyopencv_from(tvec));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_solvePnPRefineVVS(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    Mat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_rvec = NULL;
    Mat rvec;
    PyObject* pyobj_tvec = NULL;
    Mat tvec;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 20, FLT_EPSILON);
    PyObject* pyobj_VVSlambda = NULL;
    double VVSlambda=1;

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "rvec", "tvec", "criteria", "VVSlambda", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OO:solvePnPRefineVVS", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvec, &pyobj_tvec, &pyobj_criteria, &pyobj_VVSlambda) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 1)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 1)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to(pyobj_VVSlambda, VVSlambda, ArgInfo("VVSlambda", 0)) )
    {
        ERRWRAP2(cv::solvePnPRefineVVS(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, criteria, VVSlambda));
        return Py_BuildValue("(NN)", pyopencv_from(rvec), pyopencv_from(tvec));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    UMat imagePoints;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_rvec = NULL;
    UMat rvec;
    PyObject* pyobj_tvec = NULL;
    UMat tvec;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 20, FLT_EPSILON);
    PyObject* pyobj_VVSlambda = NULL;
    double VVSlambda=1;

    const char* keywords[] = { "objectPoints", "imagePoints", "cameraMatrix", "distCoeffs", "rvec", "tvec", "criteria", "VVSlambda", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OO:solvePnPRefineVVS", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_rvec, &pyobj_tvec, &pyobj_criteria, &pyobj_VVSlambda) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 1)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 1)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to(pyobj_VVSlambda, VVSlambda, ArgInfo("VVSlambda", 0)) )
    {
        ERRWRAP2(cv::solvePnPRefineVVS(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, criteria, VVSlambda));
        return Py_BuildValue("(NN)", pyopencv_from(rvec), pyopencv_from(tvec));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_solvePoly(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_coeffs = NULL;
    Mat coeffs;
    PyObject* pyobj_roots = NULL;
    Mat roots;
    PyObject* pyobj_maxIters = NULL;
    int maxIters=300;
    double retval;

    const char* keywords[] = { "coeffs", "roots", "maxIters", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:solvePoly", (char**)keywords, &pyobj_coeffs, &pyobj_roots, &pyobj_maxIters) &&
        pyopencv_to(pyobj_coeffs, coeffs, ArgInfo("coeffs", 0)) &&
        pyopencv_to(pyobj_roots, roots, ArgInfo("roots", 1)) &&
        pyopencv_to(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) )
    {
        ERRWRAP2(retval = cv::solvePoly(coeffs, roots, maxIters));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(roots));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_coeffs = NULL;
    UMat coeffs;
    PyObject* pyobj_roots = NULL;
    UMat roots;
    PyObject* pyobj_maxIters = NULL;
    int maxIters=300;
    double retval;

    const char* keywords[] = { "coeffs", "roots", "maxIters", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:solvePoly", (char**)keywords, &pyobj_coeffs, &pyobj_roots, &pyobj_maxIters) &&
        pyopencv_to(pyobj_coeffs, coeffs, ArgInfo("coeffs", 0)) &&
        pyopencv_to(pyobj_roots, roots, ArgInfo("roots", 1)) &&
        pyopencv_to(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) )
    {
        ERRWRAP2(retval = cv::solvePoly(coeffs, roots, maxIters));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(roots));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_sort(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:sort", (char**)keywords, &pyobj_src, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::sort(src, dst, flags));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:sort", (char**)keywords, &pyobj_src, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::sort(src, dst, flags));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_sortIdx(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:sortIdx", (char**)keywords, &pyobj_src, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::sortIdx(src, dst, flags));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:sortIdx", (char**)keywords, &pyobj_src, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::sortIdx(src, dst, flags));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_spatialGradient(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dx = NULL;
    Mat dx;
    PyObject* pyobj_dy = NULL;
    Mat dy;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dx", "dy", "ksize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:spatialGradient", (char**)keywords, &pyobj_src, &pyobj_dx, &pyobj_dy, &pyobj_ksize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dx, dx, ArgInfo("dx", 1)) &&
        pyopencv_to(pyobj_dy, dy, ArgInfo("dy", 1)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::spatialGradient(src, dx, dy, ksize, borderType));
        return Py_BuildValue("(NN)", pyopencv_from(dx), pyopencv_from(dy));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dx = NULL;
    UMat dx;
    PyObject* pyobj_dy = NULL;
    UMat dy;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dx", "dy", "ksize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOO:spatialGradient", (char**)keywords, &pyobj_src, &pyobj_dx, &pyobj_dy, &pyobj_ksize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dx, dx, ArgInfo("dx", 1)) &&
        pyopencv_to(pyobj_dy, dy, ArgInfo("dy", 1)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::spatialGradient(src, dx, dy, ksize, borderType));
        return Py_BuildValue("(NN)", pyopencv_from(dx), pyopencv_from(dy));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_split(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_m = NULL;
    Mat m;
    PyObject* pyobj_mv = NULL;
    vector_Mat mv;

    const char* keywords[] = { "m", "mv", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:split", (char**)keywords, &pyobj_m, &pyobj_mv) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to(pyobj_mv, mv, ArgInfo("mv", 1)) )
    {
        ERRWRAP2(cv::split(m, mv));
        return pyopencv_from(mv);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_m = NULL;
    UMat m;
    PyObject* pyobj_mv = NULL;
    vector_UMat mv;

    const char* keywords[] = { "m", "mv", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:split", (char**)keywords, &pyobj_m, &pyobj_mv) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to(pyobj_mv, mv, ArgInfo("mv", 1)) )
    {
        ERRWRAP2(cv::split(m, mv));
        return pyopencv_from(mv);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_sqrBoxFilter(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1, -1);
    PyObject* pyobj_normalize = NULL;
    bool normalize=true;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "ksize", "dst", "anchor", "normalize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:sqrBoxFilter", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_normalize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::sqrBoxFilter(src, dst, ddepth, ksize, anchor, normalize, borderType));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1, -1);
    PyObject* pyobj_normalize = NULL;
    bool normalize=true;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "ksize", "dst", "anchor", "normalize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:sqrBoxFilter", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_normalize, &pyobj_borderType) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::sqrBoxFilter(src, dst, ddepth, ksize, anchor, normalize, borderType));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_sqrt(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:sqrt", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::sqrt(src, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:sqrt", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::sqrt(src, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_startWindowThread(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::startWindowThread());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_stereoCalibrate(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_Mat objectPoints;
    PyObject* pyobj_imagePoints1 = NULL;
    vector_Mat imagePoints1;
    PyObject* pyobj_imagePoints2 = NULL;
    vector_Mat imagePoints2;
    PyObject* pyobj_cameraMatrix1 = NULL;
    Mat cameraMatrix1;
    PyObject* pyobj_distCoeffs1 = NULL;
    Mat distCoeffs1;
    PyObject* pyobj_cameraMatrix2 = NULL;
    Mat cameraMatrix2;
    PyObject* pyobj_distCoeffs2 = NULL;
    Mat distCoeffs2;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_T = NULL;
    Mat T;
    PyObject* pyobj_E = NULL;
    Mat E;
    PyObject* pyobj_F = NULL;
    Mat F;
    PyObject* pyobj_flags = NULL;
    int flags=CALIB_FIX_INTRINSIC;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 1e-6);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints1", "imagePoints2", "cameraMatrix1", "distCoeffs1", "cameraMatrix2", "distCoeffs2", "imageSize", "R", "T", "E", "F", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOO|OOOOOO:stereoCalibrate", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints1, &pyobj_imagePoints2, &pyobj_cameraMatrix1, &pyobj_distCoeffs1, &pyobj_cameraMatrix2, &pyobj_distCoeffs2, &pyobj_imageSize, &pyobj_R, &pyobj_T, &pyobj_E, &pyobj_F, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints1, imagePoints1, ArgInfo("imagePoints1", 0)) &&
        pyopencv_to(pyobj_imagePoints2, imagePoints2, ArgInfo("imagePoints2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix1, cameraMatrix1, ArgInfo("cameraMatrix1", 1)) &&
        pyopencv_to(pyobj_distCoeffs1, distCoeffs1, ArgInfo("distCoeffs1", 1)) &&
        pyopencv_to(pyobj_cameraMatrix2, cameraMatrix2, ArgInfo("cameraMatrix2", 1)) &&
        pyopencv_to(pyobj_distCoeffs2, distCoeffs2, ArgInfo("distCoeffs2", 1)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_T, T, ArgInfo("T", 1)) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 1)) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::stereoCalibrate(objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, flags, criteria));
        return Py_BuildValue("(NNNNNNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix1), pyopencv_from(distCoeffs1), pyopencv_from(cameraMatrix2), pyopencv_from(distCoeffs2), pyopencv_from(R), pyopencv_from(T), pyopencv_from(E), pyopencv_from(F));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_UMat objectPoints;
    PyObject* pyobj_imagePoints1 = NULL;
    vector_UMat imagePoints1;
    PyObject* pyobj_imagePoints2 = NULL;
    vector_UMat imagePoints2;
    PyObject* pyobj_cameraMatrix1 = NULL;
    UMat cameraMatrix1;
    PyObject* pyobj_distCoeffs1 = NULL;
    UMat distCoeffs1;
    PyObject* pyobj_cameraMatrix2 = NULL;
    UMat cameraMatrix2;
    PyObject* pyobj_distCoeffs2 = NULL;
    UMat distCoeffs2;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_T = NULL;
    UMat T;
    PyObject* pyobj_E = NULL;
    UMat E;
    PyObject* pyobj_F = NULL;
    UMat F;
    PyObject* pyobj_flags = NULL;
    int flags=CALIB_FIX_INTRINSIC;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 1e-6);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints1", "imagePoints2", "cameraMatrix1", "distCoeffs1", "cameraMatrix2", "distCoeffs2", "imageSize", "R", "T", "E", "F", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOO|OOOOOO:stereoCalibrate", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints1, &pyobj_imagePoints2, &pyobj_cameraMatrix1, &pyobj_distCoeffs1, &pyobj_cameraMatrix2, &pyobj_distCoeffs2, &pyobj_imageSize, &pyobj_R, &pyobj_T, &pyobj_E, &pyobj_F, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints1, imagePoints1, ArgInfo("imagePoints1", 0)) &&
        pyopencv_to(pyobj_imagePoints2, imagePoints2, ArgInfo("imagePoints2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix1, cameraMatrix1, ArgInfo("cameraMatrix1", 1)) &&
        pyopencv_to(pyobj_distCoeffs1, distCoeffs1, ArgInfo("distCoeffs1", 1)) &&
        pyopencv_to(pyobj_cameraMatrix2, cameraMatrix2, ArgInfo("cameraMatrix2", 1)) &&
        pyopencv_to(pyobj_distCoeffs2, distCoeffs2, ArgInfo("distCoeffs2", 1)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_T, T, ArgInfo("T", 1)) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 1)) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::stereoCalibrate(objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, flags, criteria));
        return Py_BuildValue("(NNNNNNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix1), pyopencv_from(distCoeffs1), pyopencv_from(cameraMatrix2), pyopencv_from(distCoeffs2), pyopencv_from(R), pyopencv_from(T), pyopencv_from(E), pyopencv_from(F));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_stereoCalibrateExtended(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_Mat objectPoints;
    PyObject* pyobj_imagePoints1 = NULL;
    vector_Mat imagePoints1;
    PyObject* pyobj_imagePoints2 = NULL;
    vector_Mat imagePoints2;
    PyObject* pyobj_cameraMatrix1 = NULL;
    Mat cameraMatrix1;
    PyObject* pyobj_distCoeffs1 = NULL;
    Mat distCoeffs1;
    PyObject* pyobj_cameraMatrix2 = NULL;
    Mat cameraMatrix2;
    PyObject* pyobj_distCoeffs2 = NULL;
    Mat distCoeffs2;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_T = NULL;
    Mat T;
    PyObject* pyobj_E = NULL;
    Mat E;
    PyObject* pyobj_F = NULL;
    Mat F;
    PyObject* pyobj_perViewErrors = NULL;
    Mat perViewErrors;
    PyObject* pyobj_flags = NULL;
    int flags=CALIB_FIX_INTRINSIC;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 1e-6);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints1", "imagePoints2", "cameraMatrix1", "distCoeffs1", "cameraMatrix2", "distCoeffs2", "imageSize", "R", "T", "E", "F", "perViewErrors", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOO|OOOOO:stereoCalibrateExtended", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints1, &pyobj_imagePoints2, &pyobj_cameraMatrix1, &pyobj_distCoeffs1, &pyobj_cameraMatrix2, &pyobj_distCoeffs2, &pyobj_imageSize, &pyobj_R, &pyobj_T, &pyobj_E, &pyobj_F, &pyobj_perViewErrors, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints1, imagePoints1, ArgInfo("imagePoints1", 0)) &&
        pyopencv_to(pyobj_imagePoints2, imagePoints2, ArgInfo("imagePoints2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix1, cameraMatrix1, ArgInfo("cameraMatrix1", 1)) &&
        pyopencv_to(pyobj_distCoeffs1, distCoeffs1, ArgInfo("distCoeffs1", 1)) &&
        pyopencv_to(pyobj_cameraMatrix2, cameraMatrix2, ArgInfo("cameraMatrix2", 1)) &&
        pyopencv_to(pyobj_distCoeffs2, distCoeffs2, ArgInfo("distCoeffs2", 1)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_T, T, ArgInfo("T", 1)) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 1)) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 1)) &&
        pyopencv_to(pyobj_perViewErrors, perViewErrors, ArgInfo("perViewErrors", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::stereoCalibrate(objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, perViewErrors, flags, criteria));
        return Py_BuildValue("(NNNNNNNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix1), pyopencv_from(distCoeffs1), pyopencv_from(cameraMatrix2), pyopencv_from(distCoeffs2), pyopencv_from(R), pyopencv_from(T), pyopencv_from(E), pyopencv_from(F), pyopencv_from(perViewErrors));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_UMat objectPoints;
    PyObject* pyobj_imagePoints1 = NULL;
    vector_UMat imagePoints1;
    PyObject* pyobj_imagePoints2 = NULL;
    vector_UMat imagePoints2;
    PyObject* pyobj_cameraMatrix1 = NULL;
    UMat cameraMatrix1;
    PyObject* pyobj_distCoeffs1 = NULL;
    UMat distCoeffs1;
    PyObject* pyobj_cameraMatrix2 = NULL;
    UMat cameraMatrix2;
    PyObject* pyobj_distCoeffs2 = NULL;
    UMat distCoeffs2;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_T = NULL;
    UMat T;
    PyObject* pyobj_E = NULL;
    UMat E;
    PyObject* pyobj_F = NULL;
    UMat F;
    PyObject* pyobj_perViewErrors = NULL;
    UMat perViewErrors;
    PyObject* pyobj_flags = NULL;
    int flags=CALIB_FIX_INTRINSIC;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 1e-6);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints1", "imagePoints2", "cameraMatrix1", "distCoeffs1", "cameraMatrix2", "distCoeffs2", "imageSize", "R", "T", "E", "F", "perViewErrors", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOO|OOOOO:stereoCalibrateExtended", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints1, &pyobj_imagePoints2, &pyobj_cameraMatrix1, &pyobj_distCoeffs1, &pyobj_cameraMatrix2, &pyobj_distCoeffs2, &pyobj_imageSize, &pyobj_R, &pyobj_T, &pyobj_E, &pyobj_F, &pyobj_perViewErrors, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints1, imagePoints1, ArgInfo("imagePoints1", 0)) &&
        pyopencv_to(pyobj_imagePoints2, imagePoints2, ArgInfo("imagePoints2", 0)) &&
        pyopencv_to(pyobj_cameraMatrix1, cameraMatrix1, ArgInfo("cameraMatrix1", 1)) &&
        pyopencv_to(pyobj_distCoeffs1, distCoeffs1, ArgInfo("distCoeffs1", 1)) &&
        pyopencv_to(pyobj_cameraMatrix2, cameraMatrix2, ArgInfo("cameraMatrix2", 1)) &&
        pyopencv_to(pyobj_distCoeffs2, distCoeffs2, ArgInfo("distCoeffs2", 1)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_T, T, ArgInfo("T", 1)) &&
        pyopencv_to(pyobj_E, E, ArgInfo("E", 1)) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 1)) &&
        pyopencv_to(pyobj_perViewErrors, perViewErrors, ArgInfo("perViewErrors", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::stereoCalibrate(objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, perViewErrors, flags, criteria));
        return Py_BuildValue("(NNNNNNNNNN)", pyopencv_from(retval), pyopencv_from(cameraMatrix1), pyopencv_from(distCoeffs1), pyopencv_from(cameraMatrix2), pyopencv_from(distCoeffs2), pyopencv_from(R), pyopencv_from(T), pyopencv_from(E), pyopencv_from(F), pyopencv_from(perViewErrors));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_stereoRectify(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_cameraMatrix1 = NULL;
    Mat cameraMatrix1;
    PyObject* pyobj_distCoeffs1 = NULL;
    Mat distCoeffs1;
    PyObject* pyobj_cameraMatrix2 = NULL;
    Mat cameraMatrix2;
    PyObject* pyobj_distCoeffs2 = NULL;
    Mat distCoeffs2;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_T = NULL;
    Mat T;
    PyObject* pyobj_R1 = NULL;
    Mat R1;
    PyObject* pyobj_R2 = NULL;
    Mat R2;
    PyObject* pyobj_P1 = NULL;
    Mat P1;
    PyObject* pyobj_P2 = NULL;
    Mat P2;
    PyObject* pyobj_Q = NULL;
    Mat Q;
    PyObject* pyobj_flags = NULL;
    int flags=CALIB_ZERO_DISPARITY;
    PyObject* pyobj_alpha = NULL;
    double alpha=-1;
    PyObject* pyobj_newImageSize = NULL;
    Size newImageSize;
    Rect validPixROI1;
    Rect validPixROI2;

    const char* keywords[] = { "cameraMatrix1", "distCoeffs1", "cameraMatrix2", "distCoeffs2", "imageSize", "R", "T", "R1", "R2", "P1", "P2", "Q", "flags", "alpha", "newImageSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOO|OOOOOOOO:stereoRectify", (char**)keywords, &pyobj_cameraMatrix1, &pyobj_distCoeffs1, &pyobj_cameraMatrix2, &pyobj_distCoeffs2, &pyobj_imageSize, &pyobj_R, &pyobj_T, &pyobj_R1, &pyobj_R2, &pyobj_P1, &pyobj_P2, &pyobj_Q, &pyobj_flags, &pyobj_alpha, &pyobj_newImageSize) &&
        pyopencv_to(pyobj_cameraMatrix1, cameraMatrix1, ArgInfo("cameraMatrix1", 0)) &&
        pyopencv_to(pyobj_distCoeffs1, distCoeffs1, ArgInfo("distCoeffs1", 0)) &&
        pyopencv_to(pyobj_cameraMatrix2, cameraMatrix2, ArgInfo("cameraMatrix2", 0)) &&
        pyopencv_to(pyobj_distCoeffs2, distCoeffs2, ArgInfo("distCoeffs2", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_T, T, ArgInfo("T", 0)) &&
        pyopencv_to(pyobj_R1, R1, ArgInfo("R1", 1)) &&
        pyopencv_to(pyobj_R2, R2, ArgInfo("R2", 1)) &&
        pyopencv_to(pyobj_P1, P1, ArgInfo("P1", 1)) &&
        pyopencv_to(pyobj_P2, P2, ArgInfo("P2", 1)) &&
        pyopencv_to(pyobj_Q, Q, ArgInfo("Q", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_newImageSize, newImageSize, ArgInfo("newImageSize", 0)) )
    {
        ERRWRAP2(cv::stereoRectify(cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, R1, R2, P1, P2, Q, flags, alpha, newImageSize, &validPixROI1, &validPixROI2));
        return Py_BuildValue("(NNNNNNN)", pyopencv_from(R1), pyopencv_from(R2), pyopencv_from(P1), pyopencv_from(P2), pyopencv_from(Q), pyopencv_from(validPixROI1), pyopencv_from(validPixROI2));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_cameraMatrix1 = NULL;
    UMat cameraMatrix1;
    PyObject* pyobj_distCoeffs1 = NULL;
    UMat distCoeffs1;
    PyObject* pyobj_cameraMatrix2 = NULL;
    UMat cameraMatrix2;
    PyObject* pyobj_distCoeffs2 = NULL;
    UMat distCoeffs2;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_T = NULL;
    UMat T;
    PyObject* pyobj_R1 = NULL;
    UMat R1;
    PyObject* pyobj_R2 = NULL;
    UMat R2;
    PyObject* pyobj_P1 = NULL;
    UMat P1;
    PyObject* pyobj_P2 = NULL;
    UMat P2;
    PyObject* pyobj_Q = NULL;
    UMat Q;
    PyObject* pyobj_flags = NULL;
    int flags=CALIB_ZERO_DISPARITY;
    PyObject* pyobj_alpha = NULL;
    double alpha=-1;
    PyObject* pyobj_newImageSize = NULL;
    Size newImageSize;
    Rect validPixROI1;
    Rect validPixROI2;

    const char* keywords[] = { "cameraMatrix1", "distCoeffs1", "cameraMatrix2", "distCoeffs2", "imageSize", "R", "T", "R1", "R2", "P1", "P2", "Q", "flags", "alpha", "newImageSize", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOO|OOOOOOOO:stereoRectify", (char**)keywords, &pyobj_cameraMatrix1, &pyobj_distCoeffs1, &pyobj_cameraMatrix2, &pyobj_distCoeffs2, &pyobj_imageSize, &pyobj_R, &pyobj_T, &pyobj_R1, &pyobj_R2, &pyobj_P1, &pyobj_P2, &pyobj_Q, &pyobj_flags, &pyobj_alpha, &pyobj_newImageSize) &&
        pyopencv_to(pyobj_cameraMatrix1, cameraMatrix1, ArgInfo("cameraMatrix1", 0)) &&
        pyopencv_to(pyobj_distCoeffs1, distCoeffs1, ArgInfo("distCoeffs1", 0)) &&
        pyopencv_to(pyobj_cameraMatrix2, cameraMatrix2, ArgInfo("cameraMatrix2", 0)) &&
        pyopencv_to(pyobj_distCoeffs2, distCoeffs2, ArgInfo("distCoeffs2", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_T, T, ArgInfo("T", 0)) &&
        pyopencv_to(pyobj_R1, R1, ArgInfo("R1", 1)) &&
        pyopencv_to(pyobj_R2, R2, ArgInfo("R2", 1)) &&
        pyopencv_to(pyobj_P1, P1, ArgInfo("P1", 1)) &&
        pyopencv_to(pyobj_P2, P2, ArgInfo("P2", 1)) &&
        pyopencv_to(pyobj_Q, Q, ArgInfo("Q", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_newImageSize, newImageSize, ArgInfo("newImageSize", 0)) )
    {
        ERRWRAP2(cv::stereoRectify(cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, R1, R2, P1, P2, Q, flags, alpha, newImageSize, &validPixROI1, &validPixROI2));
        return Py_BuildValue("(NNNNNNN)", pyopencv_from(R1), pyopencv_from(R2), pyopencv_from(P1), pyopencv_from(P2), pyopencv_from(Q), pyopencv_from(validPixROI1), pyopencv_from(validPixROI2));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_stereoRectifyUncalibrated(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_points1 = NULL;
    Mat points1;
    PyObject* pyobj_points2 = NULL;
    Mat points2;
    PyObject* pyobj_F = NULL;
    Mat F;
    PyObject* pyobj_imgSize = NULL;
    Size imgSize;
    PyObject* pyobj_H1 = NULL;
    Mat H1;
    PyObject* pyobj_H2 = NULL;
    Mat H2;
    PyObject* pyobj_threshold = NULL;
    double threshold=5;
    bool retval;

    const char* keywords[] = { "points1", "points2", "F", "imgSize", "H1", "H2", "threshold", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:stereoRectifyUncalibrated", (char**)keywords, &pyobj_points1, &pyobj_points2, &pyobj_F, &pyobj_imgSize, &pyobj_H1, &pyobj_H2, &pyobj_threshold) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 0)) &&
        pyopencv_to(pyobj_imgSize, imgSize, ArgInfo("imgSize", 0)) &&
        pyopencv_to(pyobj_H1, H1, ArgInfo("H1", 1)) &&
        pyopencv_to(pyobj_H2, H2, ArgInfo("H2", 1)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) )
    {
        ERRWRAP2(retval = cv::stereoRectifyUncalibrated(points1, points2, F, imgSize, H1, H2, threshold));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(H1), pyopencv_from(H2));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_points1 = NULL;
    UMat points1;
    PyObject* pyobj_points2 = NULL;
    UMat points2;
    PyObject* pyobj_F = NULL;
    UMat F;
    PyObject* pyobj_imgSize = NULL;
    Size imgSize;
    PyObject* pyobj_H1 = NULL;
    UMat H1;
    PyObject* pyobj_H2 = NULL;
    UMat H2;
    PyObject* pyobj_threshold = NULL;
    double threshold=5;
    bool retval;

    const char* keywords[] = { "points1", "points2", "F", "imgSize", "H1", "H2", "threshold", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOO:stereoRectifyUncalibrated", (char**)keywords, &pyobj_points1, &pyobj_points2, &pyobj_F, &pyobj_imgSize, &pyobj_H1, &pyobj_H2, &pyobj_threshold) &&
        pyopencv_to(pyobj_points1, points1, ArgInfo("points1", 0)) &&
        pyopencv_to(pyobj_points2, points2, ArgInfo("points2", 0)) &&
        pyopencv_to(pyobj_F, F, ArgInfo("F", 0)) &&
        pyopencv_to(pyobj_imgSize, imgSize, ArgInfo("imgSize", 0)) &&
        pyopencv_to(pyobj_H1, H1, ArgInfo("H1", 1)) &&
        pyopencv_to(pyobj_H2, H2, ArgInfo("H2", 1)) &&
        pyopencv_to(pyobj_threshold, threshold, ArgInfo("threshold", 0)) )
    {
        ERRWRAP2(retval = cv::stereoRectifyUncalibrated(points1, points2, F, imgSize, H1, H2, threshold));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(H1), pyopencv_from(H2));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_stylization(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_sigma_s = NULL;
    float sigma_s=60;
    PyObject* pyobj_sigma_r = NULL;
    float sigma_r=0.45f;

    const char* keywords[] = { "src", "dst", "sigma_s", "sigma_r", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:stylization", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_sigma_s, &pyobj_sigma_r) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_sigma_s, sigma_s, ArgInfo("sigma_s", 0)) &&
        pyopencv_to(pyobj_sigma_r, sigma_r, ArgInfo("sigma_r", 0)) )
    {
        ERRWRAP2(cv::stylization(src, dst, sigma_s, sigma_r));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_sigma_s = NULL;
    float sigma_s=60;
    PyObject* pyobj_sigma_r = NULL;
    float sigma_r=0.45f;

    const char* keywords[] = { "src", "dst", "sigma_s", "sigma_r", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOO:stylization", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_sigma_s, &pyobj_sigma_r) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_sigma_s, sigma_s, ArgInfo("sigma_s", 0)) &&
        pyopencv_to(pyobj_sigma_r, sigma_r, ArgInfo("sigma_r", 0)) )
    {
        ERRWRAP2(cv::stylization(src, dst, sigma_s, sigma_r));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_subtract(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:subtract", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::subtract(src1, src2, dst, mask, dtype));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOO:subtract", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype) &&
        pyopencv_to(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::subtract(src1, src2, dst, mask, dtype));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_sumElems(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    Scalar retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:sumElems", (char**)keywords, &pyobj_src) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::sum(src));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    Scalar retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:sumElems", (char**)keywords, &pyobj_src) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::sum(src));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_textureFlattening(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_low_threshold = NULL;
    float low_threshold=30;
    PyObject* pyobj_high_threshold = NULL;
    float high_threshold=45;
    PyObject* pyobj_kernel_size = NULL;
    int kernel_size=3;

    const char* keywords[] = { "src", "mask", "dst", "low_threshold", "high_threshold", "kernel_size", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:textureFlattening", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst, &pyobj_low_threshold, &pyobj_high_threshold, &pyobj_kernel_size) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_low_threshold, low_threshold, ArgInfo("low_threshold", 0)) &&
        pyopencv_to(pyobj_high_threshold, high_threshold, ArgInfo("high_threshold", 0)) &&
        pyopencv_to(pyobj_kernel_size, kernel_size, ArgInfo("kernel_size", 0)) )
    {
        ERRWRAP2(cv::textureFlattening(src, mask, dst, low_threshold, high_threshold, kernel_size));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_low_threshold = NULL;
    float low_threshold=30;
    PyObject* pyobj_high_threshold = NULL;
    float high_threshold=45;
    PyObject* pyobj_kernel_size = NULL;
    int kernel_size=3;

    const char* keywords[] = { "src", "mask", "dst", "low_threshold", "high_threshold", "kernel_size", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|OOOO:textureFlattening", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst, &pyobj_low_threshold, &pyobj_high_threshold, &pyobj_kernel_size) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_low_threshold, low_threshold, ArgInfo("low_threshold", 0)) &&
        pyopencv_to(pyobj_high_threshold, high_threshold, ArgInfo("high_threshold", 0)) &&
        pyopencv_to(pyobj_kernel_size, kernel_size, ArgInfo("kernel_size", 0)) )
    {
        ERRWRAP2(cv::textureFlattening(src, mask, dst, low_threshold, high_threshold, kernel_size));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_threshold(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_thresh = NULL;
    double thresh=0;
    PyObject* pyobj_maxval = NULL;
    double maxval=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    double retval;

    const char* keywords[] = { "src", "thresh", "maxval", "type", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:threshold", (char**)keywords, &pyobj_src, &pyobj_thresh, &pyobj_maxval, &pyobj_type, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_thresh, thresh, ArgInfo("thresh", 0)) &&
        pyopencv_to(pyobj_maxval, maxval, ArgInfo("maxval", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = cv::threshold(src, dst, thresh, maxval, type));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_thresh = NULL;
    double thresh=0;
    PyObject* pyobj_maxval = NULL;
    double maxval=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    double retval;

    const char* keywords[] = { "src", "thresh", "maxval", "type", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:threshold", (char**)keywords, &pyobj_src, &pyobj_thresh, &pyobj_maxval, &pyobj_type, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_thresh, thresh, ArgInfo("thresh", 0)) &&
        pyopencv_to(pyobj_maxval, maxval, ArgInfo("maxval", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = cv::threshold(src, dst, thresh, maxval, type));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_trace(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_mtx = NULL;
    Mat mtx;
    Scalar retval;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:trace", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(retval = cv::trace(mtx));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_mtx = NULL;
    UMat mtx;
    Scalar retval;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:trace", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(retval = cv::trace(mtx));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_transform(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "src", "m", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:transform", (char**)keywords, &pyobj_src, &pyobj_m, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::transform(src, dst, m));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_m = NULL;
    UMat m;

    const char* keywords[] = { "src", "m", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:transform", (char**)keywords, &pyobj_src, &pyobj_m, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::transform(src, dst, m));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_transpose(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:transpose", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::transpose(src, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:transpose", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::transpose(src, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_triangulatePoints(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_projMatr1 = NULL;
    Mat projMatr1;
    PyObject* pyobj_projMatr2 = NULL;
    Mat projMatr2;
    PyObject* pyobj_projPoints1 = NULL;
    Mat projPoints1;
    PyObject* pyobj_projPoints2 = NULL;
    Mat projPoints2;
    PyObject* pyobj_points4D = NULL;
    Mat points4D;

    const char* keywords[] = { "projMatr1", "projMatr2", "projPoints1", "projPoints2", "points4D", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:triangulatePoints", (char**)keywords, &pyobj_projMatr1, &pyobj_projMatr2, &pyobj_projPoints1, &pyobj_projPoints2, &pyobj_points4D) &&
        pyopencv_to(pyobj_projMatr1, projMatr1, ArgInfo("projMatr1", 0)) &&
        pyopencv_to(pyobj_projMatr2, projMatr2, ArgInfo("projMatr2", 0)) &&
        pyopencv_to(pyobj_projPoints1, projPoints1, ArgInfo("projPoints1", 0)) &&
        pyopencv_to(pyobj_projPoints2, projPoints2, ArgInfo("projPoints2", 0)) &&
        pyopencv_to(pyobj_points4D, points4D, ArgInfo("points4D", 1)) )
    {
        ERRWRAP2(cv::triangulatePoints(projMatr1, projMatr2, projPoints1, projPoints2, points4D));
        return pyopencv_from(points4D);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_projMatr1 = NULL;
    UMat projMatr1;
    PyObject* pyobj_projMatr2 = NULL;
    UMat projMatr2;
    PyObject* pyobj_projPoints1 = NULL;
    UMat projPoints1;
    PyObject* pyobj_projPoints2 = NULL;
    UMat projPoints2;
    PyObject* pyobj_points4D = NULL;
    UMat points4D;

    const char* keywords[] = { "projMatr1", "projMatr2", "projPoints1", "projPoints2", "points4D", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:triangulatePoints", (char**)keywords, &pyobj_projMatr1, &pyobj_projMatr2, &pyobj_projPoints1, &pyobj_projPoints2, &pyobj_points4D) &&
        pyopencv_to(pyobj_projMatr1, projMatr1, ArgInfo("projMatr1", 0)) &&
        pyopencv_to(pyobj_projMatr2, projMatr2, ArgInfo("projMatr2", 0)) &&
        pyopencv_to(pyobj_projPoints1, projPoints1, ArgInfo("projPoints1", 0)) &&
        pyopencv_to(pyobj_projPoints2, projPoints2, ArgInfo("projPoints2", 0)) &&
        pyopencv_to(pyobj_points4D, points4D, ArgInfo("points4D", 1)) )
    {
        ERRWRAP2(cv::triangulatePoints(projMatr1, projMatr2, projPoints1, projPoints2, points4D));
        return pyopencv_from(points4D);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_undistort(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_newCameraMatrix = NULL;
    Mat newCameraMatrix;

    const char* keywords[] = { "src", "cameraMatrix", "distCoeffs", "dst", "newCameraMatrix", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:undistort", (char**)keywords, &pyobj_src, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_dst, &pyobj_newCameraMatrix) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_newCameraMatrix, newCameraMatrix, ArgInfo("newCameraMatrix", 0)) )
    {
        ERRWRAP2(cv::undistort(src, dst, cameraMatrix, distCoeffs, newCameraMatrix));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_newCameraMatrix = NULL;
    UMat newCameraMatrix;

    const char* keywords[] = { "src", "cameraMatrix", "distCoeffs", "dst", "newCameraMatrix", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:undistort", (char**)keywords, &pyobj_src, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_dst, &pyobj_newCameraMatrix) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_newCameraMatrix, newCameraMatrix, ArgInfo("newCameraMatrix", 0)) )
    {
        ERRWRAP2(cv::undistort(src, dst, cameraMatrix, distCoeffs, newCameraMatrix));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_undistortPoints(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_P = NULL;
    Mat P;

    const char* keywords[] = { "src", "cameraMatrix", "distCoeffs", "dst", "R", "P", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:undistortPoints", (char**)keywords, &pyobj_src, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_dst, &pyobj_R, &pyobj_P) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_P, P, ArgInfo("P", 0)) )
    {
        ERRWRAP2(cv::undistortPoints(src, dst, cameraMatrix, distCoeffs, R, P));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_P = NULL;
    UMat P;

    const char* keywords[] = { "src", "cameraMatrix", "distCoeffs", "dst", "R", "P", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:undistortPoints", (char**)keywords, &pyobj_src, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_dst, &pyobj_R, &pyobj_P) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_P, P, ArgInfo("P", 0)) )
    {
        ERRWRAP2(cv::undistortPoints(src, dst, cameraMatrix, distCoeffs, R, P));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_undistortPointsIter(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_cameraMatrix = NULL;
    Mat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    Mat distCoeffs;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_P = NULL;
    Mat P;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;

    const char* keywords[] = { "src", "cameraMatrix", "distCoeffs", "R", "P", "criteria", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:undistortPointsIter", (char**)keywords, &pyobj_src, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_R, &pyobj_P, &pyobj_criteria, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_P, P, ArgInfo("P", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(cv::undistortPoints(src, dst, cameraMatrix, distCoeffs, R, P, criteria));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_cameraMatrix = NULL;
    UMat cameraMatrix;
    PyObject* pyobj_distCoeffs = NULL;
    UMat distCoeffs;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_P = NULL;
    UMat P;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;

    const char* keywords[] = { "src", "cameraMatrix", "distCoeffs", "R", "P", "criteria", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|O:undistortPointsIter", (char**)keywords, &pyobj_src, &pyobj_cameraMatrix, &pyobj_distCoeffs, &pyobj_R, &pyobj_P, &pyobj_criteria, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_cameraMatrix, cameraMatrix, ArgInfo("cameraMatrix", 0)) &&
        pyopencv_to(pyobj_distCoeffs, distCoeffs, ArgInfo("distCoeffs", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_P, P, ArgInfo("P", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(cv::undistortPoints(src, dst, cameraMatrix, distCoeffs, R, P, criteria));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_useOpenVX(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    bool retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::useOpenVX());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_useOptimized(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    bool retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::useOptimized());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_validateDisparity(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_disparity = NULL;
    Mat disparity;
    PyObject* pyobj_cost = NULL;
    Mat cost;
    PyObject* pyobj_minDisparity = NULL;
    int minDisparity=0;
    PyObject* pyobj_numberOfDisparities = NULL;
    int numberOfDisparities=0;
    PyObject* pyobj_disp12MaxDisp = NULL;
    int disp12MaxDisp=1;

    const char* keywords[] = { "disparity", "cost", "minDisparity", "numberOfDisparities", "disp12MaxDisp", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:validateDisparity", (char**)keywords, &pyobj_disparity, &pyobj_cost, &pyobj_minDisparity, &pyobj_numberOfDisparities, &pyobj_disp12MaxDisp) &&
        pyopencv_to(pyobj_disparity, disparity, ArgInfo("disparity", 1)) &&
        pyopencv_to(pyobj_cost, cost, ArgInfo("cost", 0)) &&
        pyopencv_to(pyobj_minDisparity, minDisparity, ArgInfo("minDisparity", 0)) &&
        pyopencv_to(pyobj_numberOfDisparities, numberOfDisparities, ArgInfo("numberOfDisparities", 0)) &&
        pyopencv_to(pyobj_disp12MaxDisp, disp12MaxDisp, ArgInfo("disp12MaxDisp", 0)) )
    {
        ERRWRAP2(cv::validateDisparity(disparity, cost, minDisparity, numberOfDisparities, disp12MaxDisp));
        return pyopencv_from(disparity);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_disparity = NULL;
    UMat disparity;
    PyObject* pyobj_cost = NULL;
    UMat cost;
    PyObject* pyobj_minDisparity = NULL;
    int minDisparity=0;
    PyObject* pyobj_numberOfDisparities = NULL;
    int numberOfDisparities=0;
    PyObject* pyobj_disp12MaxDisp = NULL;
    int disp12MaxDisp=1;

    const char* keywords[] = { "disparity", "cost", "minDisparity", "numberOfDisparities", "disp12MaxDisp", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|O:validateDisparity", (char**)keywords, &pyobj_disparity, &pyobj_cost, &pyobj_minDisparity, &pyobj_numberOfDisparities, &pyobj_disp12MaxDisp) &&
        pyopencv_to(pyobj_disparity, disparity, ArgInfo("disparity", 1)) &&
        pyopencv_to(pyobj_cost, cost, ArgInfo("cost", 0)) &&
        pyopencv_to(pyobj_minDisparity, minDisparity, ArgInfo("minDisparity", 0)) &&
        pyopencv_to(pyobj_numberOfDisparities, numberOfDisparities, ArgInfo("numberOfDisparities", 0)) &&
        pyopencv_to(pyobj_disp12MaxDisp, disp12MaxDisp, ArgInfo("disp12MaxDisp", 0)) )
    {
        ERRWRAP2(cv::validateDisparity(disparity, cost, minDisparity, numberOfDisparities, disp12MaxDisp));
        return pyopencv_from(disparity);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_vconcat(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    vector_Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:vconcat", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::vconcat(src, dst));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    vector_UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:vconcat", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::vconcat(src, dst));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_waitKey(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_delay = NULL;
    int delay=0;
    int retval;

    const char* keywords[] = { "delay", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|O:waitKey", (char**)keywords, &pyobj_delay) &&
        pyopencv_to(pyobj_delay, delay, ArgInfo("delay", 0)) )
    {
        ERRWRAP2(retval = cv::waitKey(delay));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_waitKeyEx(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_delay = NULL;
    int delay=0;
    int retval;

    const char* keywords[] = { "delay", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|O:waitKeyEx", (char**)keywords, &pyobj_delay) &&
        pyopencv_to(pyobj_delay, delay, ArgInfo("delay", 0)) )
    {
        ERRWRAP2(retval = cv::waitKeyEx(delay));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_warpAffine(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:warpAffine", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:warpAffine", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_warpPerspective(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:warpPerspective", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:warpPerspective", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_warpPolar(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_maxRadius = NULL;
    double maxRadius=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dsize", "center", "maxRadius", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|O:warpPolar", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_center, &pyobj_maxRadius, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::warpPolar(src, dst, dsize, center, maxRadius, flags));
        return pyopencv_from(dst);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_maxRadius = NULL;
    double maxRadius=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dsize", "center", "maxRadius", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|O:warpPolar", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_center, &pyobj_maxRadius, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::warpPolar(src, dst, dsize, center, maxRadius, flags));
        return pyopencv_from(dst);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_watershed(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_markers = NULL;
    Mat markers;

    const char* keywords[] = { "image", "markers", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:watershed", (char**)keywords, &pyobj_image, &pyobj_markers) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_markers, markers, ArgInfo("markers", 1)) )
    {
        ERRWRAP2(cv::watershed(image, markers));
        return pyopencv_from(markers);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_markers = NULL;
    UMat markers;

    const char* keywords[] = { "image", "markers", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:watershed", (char**)keywords, &pyobj_image, &pyobj_markers) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_markers, markers, ArgInfo("markers", 1)) )
    {
        ERRWRAP2(cv::watershed(image, markers));
        return pyopencv_from(markers);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_writeOpticalFlow(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv;

    {
    PyObject* pyobj_path = NULL;
    String path;
    PyObject* pyobj_flow = NULL;
    Mat flow;
    bool retval;

    const char* keywords[] = { "path", "flow", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:writeOpticalFlow", (char**)keywords, &pyobj_path, &pyobj_flow) &&
        pyopencv_to(pyobj_path, path, ArgInfo("path", 0)) &&
        pyopencv_to(pyobj_flow, flow, ArgInfo("flow", 0)) )
    {
        ERRWRAP2(retval = cv::writeOpticalFlow(path, flow));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_path = NULL;
    String path;
    PyObject* pyobj_flow = NULL;
    UMat flow;
    bool retval;

    const char* keywords[] = { "path", "flow", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:writeOpticalFlow", (char**)keywords, &pyobj_path, &pyobj_flow) &&
        pyopencv_to(pyobj_path, path, ArgInfo("path", 0)) &&
        pyopencv_to(pyobj_flow, flow, ArgInfo("flow", 0)) )
    {
        ERRWRAP2(retval = cv::writeOpticalFlow(path, flow));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_Event_elapsedTime(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_start = NULL;
    Event start;
    PyObject* pyobj_end = NULL;
    Event end;
    float retval;

    const char* keywords[] = { "start", "end", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:Event_elapsedTime", (char**)keywords, &pyobj_start, &pyobj_end) &&
        pyopencv_to(pyobj_start, start, ArgInfo("start", 0)) &&
        pyopencv_to(pyobj_end, end, ArgInfo("end", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::Event::elapsedTime(start, end));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_GpuMat_defaultAllocator(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    GpuMat::Allocator* retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::GpuMat::defaultAllocator());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_GpuMat_setDefaultAllocator(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator;

    const char* keywords[] = { "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:GpuMat_setDefaultAllocator", (char**)keywords, &pyobj_allocator) &&
        pyopencv_to(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        ERRWRAP2(cv::cuda::GpuMat::setDefaultAllocator(allocator));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_Stream_Null(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    Stream retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::Stream::Null());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_has(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:TargetArchs_has", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::has(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasBin(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:TargetArchs_hasBin", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasBin(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasEqualOrGreater(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:TargetArchs_hasEqualOrGreater", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrGreater(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasEqualOrGreaterBin(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:TargetArchs_hasEqualOrGreaterBin", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrGreaterBin(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasEqualOrGreaterPtx(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:TargetArchs_hasEqualOrGreaterPtx", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrGreaterPtx(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasEqualOrLessPtx(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:TargetArchs_hasEqualOrLessPtx", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrLessPtx(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasPtx(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:TargetArchs_hasPtx", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasPtx(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createContinuous(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    Mat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:createContinuous", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::createContinuous(rows, cols, type, arr));
        return pyopencv_from(arr);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    cuda::GpuMat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:createContinuous", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::createContinuous(rows, cols, type, arr));
        return pyopencv_from(arr);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    UMat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:createContinuous", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::createContinuous(rows, cols, type, arr));
        return pyopencv_from(arr);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_ensureSizeIsEnough(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    Mat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:ensureSizeIsEnough", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::ensureSizeIsEnough(rows, cols, type, arr));
        return pyopencv_from(arr);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    cuda::GpuMat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:ensureSizeIsEnough", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::ensureSizeIsEnough(rows, cols, type, arr));
        return pyopencv_from(arr);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    UMat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|O:ensureSizeIsEnough", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::ensureSizeIsEnough(rows, cols, type, arr));
        return pyopencv_from(arr);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_getCudaEnabledDeviceCount(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    int retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::getCudaEnabledDeviceCount());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_getDevice(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    int retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::getDevice());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_printCudaDeviceInfo(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_device = NULL;
    int device=0;

    const char* keywords[] = { "device", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:printCudaDeviceInfo", (char**)keywords, &pyobj_device) &&
        pyopencv_to(pyobj_device, device, ArgInfo("device", 0)) )
    {
        ERRWRAP2(cv::cuda::printCudaDeviceInfo(device));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_printShortCudaDeviceInfo(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_device = NULL;
    int device=0;

    const char* keywords[] = { "device", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:printShortCudaDeviceInfo", (char**)keywords, &pyobj_device) &&
        pyopencv_to(pyobj_device, device, ArgInfo("device", 0)) )
    {
        ERRWRAP2(cv::cuda::printShortCudaDeviceInfo(device));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_registerPageLocked(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    {
    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:registerPageLocked", (char**)keywords, &pyobj_m) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::cuda::registerPageLocked(m));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:registerPageLocked", (char**)keywords, &pyobj_m) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::cuda::registerPageLocked(m));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:registerPageLocked", (char**)keywords, &pyobj_m) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::cuda::registerPageLocked(m));
        Py_RETURN_NONE;
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_resetDevice(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;


    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(cv::cuda::resetDevice());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_setBufferPoolConfig(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_deviceId = NULL;
    int deviceId=0;
    PyObject* pyobj_stackSize = NULL;
    size_t stackSize=0;
    PyObject* pyobj_stackCount = NULL;
    int stackCount=0;

    const char* keywords[] = { "deviceId", "stackSize", "stackCount", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:setBufferPoolConfig", (char**)keywords, &pyobj_deviceId, &pyobj_stackSize, &pyobj_stackCount) &&
        pyopencv_to(pyobj_deviceId, deviceId, ArgInfo("deviceId", 0)) &&
        pyopencv_to(pyobj_stackSize, stackSize, ArgInfo("stackSize", 0)) &&
        pyopencv_to(pyobj_stackCount, stackCount, ArgInfo("stackCount", 0)) )
    {
        ERRWRAP2(cv::cuda::setBufferPoolConfig(deviceId, stackSize, stackCount));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_setBufferPoolUsage(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_on = NULL;
    bool on=0;

    const char* keywords[] = { "on", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:setBufferPoolUsage", (char**)keywords, &pyobj_on) &&
        pyopencv_to(pyobj_on, on, ArgInfo("on", 0)) )
    {
        ERRWRAP2(cv::cuda::setBufferPoolUsage(on));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_setDevice(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_device = NULL;
    int device=0;

    const char* keywords[] = { "device", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:setDevice", (char**)keywords, &pyobj_device) &&
        pyopencv_to(pyobj_device, device, ArgInfo("device", 0)) )
    {
        ERRWRAP2(cv::cuda::setDevice(device));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_unregisterPageLocked(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::cuda;

    {
    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:unregisterPageLocked", (char**)keywords, &pyobj_m) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::cuda::unregisterPageLocked(m));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:unregisterPageLocked", (char**)keywords, &pyobj_m) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::cuda::unregisterPageLocked(m));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:unregisterPageLocked", (char**)keywords, &pyobj_m) &&
        pyopencv_to(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::cuda::unregisterPageLocked(m));
        Py_RETURN_NONE;
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_BestOf2NearestMatcher_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_try_use_gpu = NULL;
    bool try_use_gpu=false;
    PyObject* pyobj_match_conf = NULL;
    float match_conf=0.3f;
    PyObject* pyobj_num_matches_thresh1 = NULL;
    int num_matches_thresh1=6;
    PyObject* pyobj_num_matches_thresh2 = NULL;
    int num_matches_thresh2=6;
    Ptr<BestOf2NearestMatcher> retval;

    const char* keywords[] = { "try_use_gpu", "match_conf", "num_matches_thresh1", "num_matches_thresh2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOOO:BestOf2NearestMatcher_create", (char**)keywords, &pyobj_try_use_gpu, &pyobj_match_conf, &pyobj_num_matches_thresh1, &pyobj_num_matches_thresh2) &&
        pyopencv_to(pyobj_try_use_gpu, try_use_gpu, ArgInfo("try_use_gpu", 0)) &&
        pyopencv_to(pyobj_match_conf, match_conf, ArgInfo("match_conf", 0)) &&
        pyopencv_to(pyobj_num_matches_thresh1, num_matches_thresh1, ArgInfo("num_matches_thresh1", 0)) &&
        pyopencv_to(pyobj_num_matches_thresh2, num_matches_thresh2, ArgInfo("num_matches_thresh2", 0)) )
    {
        ERRWRAP2(retval = cv::detail::BestOf2NearestMatcher::create(try_use_gpu, match_conf, num_matches_thresh1, num_matches_thresh2));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_Blender_createDefault(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_try_gpu = NULL;
    bool try_gpu=false;
    Ptr<Blender> retval;

    const char* keywords[] = { "type", "try_gpu", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:Blender_createDefault", (char**)keywords, &pyobj_type, &pyobj_try_gpu) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to(pyobj_try_gpu, try_gpu, ArgInfo("try_gpu", 0)) )
    {
        ERRWRAP2(retval = cv::detail::Blender::createDefault(type, try_gpu));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_ExposureCompensator_createDefault(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_type = NULL;
    int type=0;
    Ptr<ExposureCompensator> retval;

    const char* keywords[] = { "type", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:ExposureCompensator_createDefault", (char**)keywords, &pyobj_type) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = cv::detail::ExposureCompensator::createDefault(type));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_SeamFinder_createDefault(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_type = NULL;
    int type=0;
    Ptr<SeamFinder> retval;

    const char* keywords[] = { "type", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:SeamFinder_createDefault", (char**)keywords, &pyobj_type) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = cv::detail::SeamFinder::createDefault(type));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_Timelapser_createDefault(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_type = NULL;
    int type=0;
    Ptr<Timelapser> retval;

    const char* keywords[] = { "type", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:Timelapser_createDefault", (char**)keywords, &pyobj_type) &&
        pyopencv_to(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = cv::detail::Timelapser::createDefault(type));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_calibrateRotatingCamera(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    {
    PyObject* pyobj_Hs = NULL;
    vector_Mat Hs;
    PyObject* pyobj_K = NULL;
    Mat K;
    bool retval;

    const char* keywords[] = { "Hs", "K", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:calibrateRotatingCamera", (char**)keywords, &pyobj_Hs, &pyobj_K) &&
        pyopencv_to(pyobj_Hs, Hs, ArgInfo("Hs", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 1)) )
    {
        ERRWRAP2(retval = cv::detail::calibrateRotatingCamera(Hs, K));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(K));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_Hs = NULL;
    vector_Mat Hs;
    PyObject* pyobj_K = NULL;
    Mat K;
    bool retval;

    const char* keywords[] = { "Hs", "K", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:calibrateRotatingCamera", (char**)keywords, &pyobj_Hs, &pyobj_K) &&
        pyopencv_to(pyobj_Hs, Hs, ArgInfo("Hs", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 1)) )
    {
        ERRWRAP2(retval = cv::detail::calibrateRotatingCamera(Hs, K));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(K));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_computeImageFeatures(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    {
    PyObject* pyobj_featuresFinder = NULL;
    Ptr<Feature2D> featuresFinder;
    PyObject* pyobj_images = NULL;
    vector_Mat images;
    vector_ImageFeatures features;
    PyObject* pyobj_masks = NULL;
    vector_Mat masks;

    const char* keywords[] = { "featuresFinder", "images", "masks", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:computeImageFeatures", (char**)keywords, &pyobj_featuresFinder, &pyobj_images, &pyobj_masks) &&
        pyopencv_to(pyobj_featuresFinder, featuresFinder, ArgInfo("featuresFinder", 0)) &&
        pyopencv_to(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to(pyobj_masks, masks, ArgInfo("masks", 0)) )
    {
        ERRWRAP2(cv::detail::computeImageFeatures(featuresFinder, images, features, masks));
        return pyopencv_from(features);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_featuresFinder = NULL;
    Ptr<Feature2D> featuresFinder;
    PyObject* pyobj_images = NULL;
    vector_UMat images;
    vector_ImageFeatures features;
    PyObject* pyobj_masks = NULL;
    vector_UMat masks;

    const char* keywords[] = { "featuresFinder", "images", "masks", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:computeImageFeatures", (char**)keywords, &pyobj_featuresFinder, &pyobj_images, &pyobj_masks) &&
        pyopencv_to(pyobj_featuresFinder, featuresFinder, ArgInfo("featuresFinder", 0)) &&
        pyopencv_to(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to(pyobj_masks, masks, ArgInfo("masks", 0)) )
    {
        ERRWRAP2(cv::detail::computeImageFeatures(featuresFinder, images, features, masks));
        return pyopencv_from(features);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_computeImageFeatures2(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    {
    PyObject* pyobj_featuresFinder = NULL;
    Ptr<Feature2D> featuresFinder;
    PyObject* pyobj_image = NULL;
    Mat image;
    ImageFeatures features;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "featuresFinder", "image", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:computeImageFeatures2", (char**)keywords, &pyobj_featuresFinder, &pyobj_image, &pyobj_mask) &&
        pyopencv_to(pyobj_featuresFinder, featuresFinder, ArgInfo("featuresFinder", 0)) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::detail::computeImageFeatures(featuresFinder, image, features, mask));
        return pyopencv_from(features);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_featuresFinder = NULL;
    Ptr<Feature2D> featuresFinder;
    PyObject* pyobj_image = NULL;
    UMat image;
    ImageFeatures features;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "featuresFinder", "image", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:computeImageFeatures2", (char**)keywords, &pyobj_featuresFinder, &pyobj_image, &pyobj_mask) &&
        pyopencv_to(pyobj_featuresFinder, featuresFinder, ArgInfo("featuresFinder", 0)) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::detail::computeImageFeatures(featuresFinder, image, features, mask));
        return pyopencv_from(features);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_createLaplacePyr(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_num_levels = NULL;
    int num_levels=0;
    PyObject* pyobj_pyr = NULL;
    vector_UMat pyr;

    const char* keywords[] = { "img", "num_levels", "pyr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:createLaplacePyr", (char**)keywords, &pyobj_img, &pyobj_num_levels, &pyobj_pyr) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_num_levels, num_levels, ArgInfo("num_levels", 0)) &&
        pyopencv_to(pyobj_pyr, pyr, ArgInfo("pyr", 1)) )
    {
        ERRWRAP2(cv::detail::createLaplacePyr(img, num_levels, pyr));
        return pyopencv_from(pyr);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_num_levels = NULL;
    int num_levels=0;
    PyObject* pyobj_pyr = NULL;
    vector_UMat pyr;

    const char* keywords[] = { "img", "num_levels", "pyr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:createLaplacePyr", (char**)keywords, &pyobj_img, &pyobj_num_levels, &pyobj_pyr) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_num_levels, num_levels, ArgInfo("num_levels", 0)) &&
        pyopencv_to(pyobj_pyr, pyr, ArgInfo("pyr", 1)) )
    {
        ERRWRAP2(cv::detail::createLaplacePyr(img, num_levels, pyr));
        return pyopencv_from(pyr);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_createLaplacePyrGpu(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_num_levels = NULL;
    int num_levels=0;
    PyObject* pyobj_pyr = NULL;
    vector_UMat pyr;

    const char* keywords[] = { "img", "num_levels", "pyr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:createLaplacePyrGpu", (char**)keywords, &pyobj_img, &pyobj_num_levels, &pyobj_pyr) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_num_levels, num_levels, ArgInfo("num_levels", 0)) &&
        pyopencv_to(pyobj_pyr, pyr, ArgInfo("pyr", 1)) )
    {
        ERRWRAP2(cv::detail::createLaplacePyrGpu(img, num_levels, pyr));
        return pyopencv_from(pyr);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_num_levels = NULL;
    int num_levels=0;
    PyObject* pyobj_pyr = NULL;
    vector_UMat pyr;

    const char* keywords[] = { "img", "num_levels", "pyr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:createLaplacePyrGpu", (char**)keywords, &pyobj_img, &pyobj_num_levels, &pyobj_pyr) &&
        pyopencv_to(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to(pyobj_num_levels, num_levels, ArgInfo("num_levels", 0)) &&
        pyopencv_to(pyobj_pyr, pyr, ArgInfo("pyr", 1)) )
    {
        ERRWRAP2(cv::detail::createLaplacePyrGpu(img, num_levels, pyr));
        return pyopencv_from(pyr);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_createWeightMap(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    {
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_sharpness = NULL;
    float sharpness=0.f;
    PyObject* pyobj_weight = NULL;
    Mat weight;

    const char* keywords[] = { "mask", "sharpness", "weight", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:createWeightMap", (char**)keywords, &pyobj_mask, &pyobj_sharpness, &pyobj_weight) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_sharpness, sharpness, ArgInfo("sharpness", 0)) &&
        pyopencv_to(pyobj_weight, weight, ArgInfo("weight", 1)) )
    {
        ERRWRAP2(cv::detail::createWeightMap(mask, sharpness, weight));
        return pyopencv_from(weight);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_sharpness = NULL;
    float sharpness=0.f;
    PyObject* pyobj_weight = NULL;
    UMat weight;

    const char* keywords[] = { "mask", "sharpness", "weight", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:createWeightMap", (char**)keywords, &pyobj_mask, &pyobj_sharpness, &pyobj_weight) &&
        pyopencv_to(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to(pyobj_sharpness, sharpness, ArgInfo("sharpness", 0)) &&
        pyopencv_to(pyobj_weight, weight, ArgInfo("weight", 1)) )
    {
        ERRWRAP2(cv::detail::createWeightMap(mask, sharpness, weight));
        return pyopencv_from(weight);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_focalsFromHomography(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    {
    PyObject* pyobj_H = NULL;
    Mat H;
    PyObject* pyobj_f0 = NULL;
    double f0=0;
    PyObject* pyobj_f1 = NULL;
    double f1=0;
    PyObject* pyobj_f0_ok = NULL;
    bool f0_ok=0;
    PyObject* pyobj_f1_ok = NULL;
    bool f1_ok=0;

    const char* keywords[] = { "H", "f0", "f1", "f0_ok", "f1_ok", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO:focalsFromHomography", (char**)keywords, &pyobj_H, &pyobj_f0, &pyobj_f1, &pyobj_f0_ok, &pyobj_f1_ok) &&
        pyopencv_to(pyobj_H, H, ArgInfo("H", 0)) &&
        pyopencv_to(pyobj_f0, f0, ArgInfo("f0", 0)) &&
        pyopencv_to(pyobj_f1, f1, ArgInfo("f1", 0)) &&
        pyopencv_to(pyobj_f0_ok, f0_ok, ArgInfo("f0_ok", 0)) &&
        pyopencv_to(pyobj_f1_ok, f1_ok, ArgInfo("f1_ok", 0)) )
    {
        ERRWRAP2(cv::detail::focalsFromHomography(H, f0, f1, f0_ok, f1_ok));
        Py_RETURN_NONE;
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_H = NULL;
    Mat H;
    PyObject* pyobj_f0 = NULL;
    double f0=0;
    PyObject* pyobj_f1 = NULL;
    double f1=0;
    PyObject* pyobj_f0_ok = NULL;
    bool f0_ok=0;
    PyObject* pyobj_f1_ok = NULL;
    bool f1_ok=0;

    const char* keywords[] = { "H", "f0", "f1", "f0_ok", "f1_ok", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO:focalsFromHomography", (char**)keywords, &pyobj_H, &pyobj_f0, &pyobj_f1, &pyobj_f0_ok, &pyobj_f1_ok) &&
        pyopencv_to(pyobj_H, H, ArgInfo("H", 0)) &&
        pyopencv_to(pyobj_f0, f0, ArgInfo("f0", 0)) &&
        pyopencv_to(pyobj_f1, f1, ArgInfo("f1", 0)) &&
        pyopencv_to(pyobj_f0_ok, f0_ok, ArgInfo("f0_ok", 0)) &&
        pyopencv_to(pyobj_f1_ok, f1_ok, ArgInfo("f1_ok", 0)) )
    {
        ERRWRAP2(cv::detail::focalsFromHomography(H, f0, f1, f0_ok, f1_ok));
        Py_RETURN_NONE;
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_leaveBiggestComponent(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_features = NULL;
    vector_ImageFeatures features;
    PyObject* pyobj_pairwise_matches = NULL;
    vector_MatchesInfo pairwise_matches;
    PyObject* pyobj_conf_threshold = NULL;
    float conf_threshold=0.f;
    std::vector<int> retval;

    const char* keywords[] = { "features", "pairwise_matches", "conf_threshold", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:leaveBiggestComponent", (char**)keywords, &pyobj_features, &pyobj_pairwise_matches, &pyobj_conf_threshold) &&
        pyopencv_to(pyobj_features, features, ArgInfo("features", 0)) &&
        pyopencv_to(pyobj_pairwise_matches, pairwise_matches, ArgInfo("pairwise_matches", 0)) &&
        pyopencv_to(pyobj_conf_threshold, conf_threshold, ArgInfo("conf_threshold", 0)) )
    {
        ERRWRAP2(retval = cv::detail::leaveBiggestComponent(features, pairwise_matches, conf_threshold));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_matchesGraphAsString(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_pathes = NULL;
    vector_String pathes;
    PyObject* pyobj_pairwise_matches = NULL;
    vector_MatchesInfo pairwise_matches;
    PyObject* pyobj_conf_threshold = NULL;
    float conf_threshold=0.f;
    String retval;

    const char* keywords[] = { "pathes", "pairwise_matches", "conf_threshold", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:matchesGraphAsString", (char**)keywords, &pyobj_pathes, &pyobj_pairwise_matches, &pyobj_conf_threshold) &&
        pyopencv_to(pyobj_pathes, pathes, ArgInfo("pathes", 0)) &&
        pyopencv_to(pyobj_pairwise_matches, pairwise_matches, ArgInfo("pairwise_matches", 0)) &&
        pyopencv_to(pyobj_conf_threshold, conf_threshold, ArgInfo("conf_threshold", 0)) )
    {
        ERRWRAP2(retval = cv::detail::matchesGraphAsString(pathes, pairwise_matches, conf_threshold));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_normalizeUsingWeightMap(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    {
    PyObject* pyobj_weight = NULL;
    Mat weight;
    PyObject* pyobj_src = NULL;
    Mat src;

    const char* keywords[] = { "weight", "src", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:normalizeUsingWeightMap", (char**)keywords, &pyobj_weight, &pyobj_src) &&
        pyopencv_to(pyobj_weight, weight, ArgInfo("weight", 0)) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 1)) )
    {
        ERRWRAP2(cv::detail::normalizeUsingWeightMap(weight, src));
        return pyopencv_from(src);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_weight = NULL;
    UMat weight;
    PyObject* pyobj_src = NULL;
    UMat src;

    const char* keywords[] = { "weight", "src", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:normalizeUsingWeightMap", (char**)keywords, &pyobj_weight, &pyobj_src) &&
        pyopencv_to(pyobj_weight, weight, ArgInfo("weight", 0)) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 1)) )
    {
        ERRWRAP2(cv::detail::normalizeUsingWeightMap(weight, src));
        return pyopencv_from(src);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_overlapRoi(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_tl1 = NULL;
    Point tl1;
    PyObject* pyobj_tl2 = NULL;
    Point tl2;
    PyObject* pyobj_sz1 = NULL;
    Size sz1;
    PyObject* pyobj_sz2 = NULL;
    Size sz2;
    PyObject* pyobj_roi = NULL;
    Rect roi;
    bool retval;

    const char* keywords[] = { "tl1", "tl2", "sz1", "sz2", "roi", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO:overlapRoi", (char**)keywords, &pyobj_tl1, &pyobj_tl2, &pyobj_sz1, &pyobj_sz2, &pyobj_roi) &&
        pyopencv_to(pyobj_tl1, tl1, ArgInfo("tl1", 0)) &&
        pyopencv_to(pyobj_tl2, tl2, ArgInfo("tl2", 0)) &&
        pyopencv_to(pyobj_sz1, sz1, ArgInfo("sz1", 0)) &&
        pyopencv_to(pyobj_sz2, sz2, ArgInfo("sz2", 0)) &&
        pyopencv_to(pyobj_roi, roi, ArgInfo("roi", 0)) )
    {
        ERRWRAP2(retval = cv::detail::overlapRoi(tl1, tl2, sz1, sz2, roi));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_restoreImageFromLaplacePyr(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_pyr = NULL;
    vector_UMat pyr;

    const char* keywords[] = { "pyr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:restoreImageFromLaplacePyr", (char**)keywords, &pyobj_pyr) &&
        pyopencv_to(pyobj_pyr, pyr, ArgInfo("pyr", 1)) )
    {
        ERRWRAP2(cv::detail::restoreImageFromLaplacePyr(pyr));
        return pyopencv_from(pyr);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_restoreImageFromLaplacePyrGpu(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_pyr = NULL;
    vector_UMat pyr;

    const char* keywords[] = { "pyr", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:restoreImageFromLaplacePyrGpu", (char**)keywords, &pyobj_pyr) &&
        pyopencv_to(pyobj_pyr, pyr, ArgInfo("pyr", 1)) )
    {
        ERRWRAP2(cv::detail::restoreImageFromLaplacePyrGpu(pyr));
        return pyopencv_from(pyr);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_resultRoi(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    {
    PyObject* pyobj_corners = NULL;
    vector_Point corners;
    PyObject* pyobj_images = NULL;
    vector_UMat images;
    Rect retval;

    const char* keywords[] = { "corners", "images", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:resultRoi", (char**)keywords, &pyobj_corners, &pyobj_images) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 0)) &&
        pyopencv_to(pyobj_images, images, ArgInfo("images", 0)) )
    {
        ERRWRAP2(retval = cv::detail::resultRoi(corners, images));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_corners = NULL;
    vector_Point corners;
    PyObject* pyobj_sizes = NULL;
    vector_Size sizes;
    Rect retval;

    const char* keywords[] = { "corners", "sizes", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:resultRoi", (char**)keywords, &pyobj_corners, &pyobj_sizes) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 0)) &&
        pyopencv_to(pyobj_sizes, sizes, ArgInfo("sizes", 0)) )
    {
        ERRWRAP2(retval = cv::detail::resultRoi(corners, sizes));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_resultRoiIntersection(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_corners = NULL;
    vector_Point corners;
    PyObject* pyobj_sizes = NULL;
    vector_Size sizes;
    Rect retval;

    const char* keywords[] = { "corners", "sizes", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:resultRoiIntersection", (char**)keywords, &pyobj_corners, &pyobj_sizes) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 0)) &&
        pyopencv_to(pyobj_sizes, sizes, ArgInfo("sizes", 0)) )
    {
        ERRWRAP2(retval = cv::detail::resultRoiIntersection(corners, sizes));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_resultTl(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_corners = NULL;
    vector_Point corners;
    Point retval;

    const char* keywords[] = { "corners", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:resultTl", (char**)keywords, &pyobj_corners) &&
        pyopencv_to(pyobj_corners, corners, ArgInfo("corners", 0)) )
    {
        ERRWRAP2(retval = cv::detail::resultTl(corners));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_selectRandomSubset(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    PyObject* pyobj_count = NULL;
    int count=0;
    PyObject* pyobj_size = NULL;
    int size=0;
    PyObject* pyobj_subset = NULL;
    vector_int subset;

    const char* keywords[] = { "count", "size", "subset", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:selectRandomSubset", (char**)keywords, &pyobj_count, &pyobj_size, &pyobj_subset) &&
        pyopencv_to(pyobj_count, count, ArgInfo("count", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to(pyobj_subset, subset, ArgInfo("subset", 0)) )
    {
        ERRWRAP2(cv::detail::selectRandomSubset(count, size, subset));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_stitchingLogLevel(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    int retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::detail::stitchingLogLevel());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_detail_waveCorrect(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::detail;

    {
    PyObject* pyobj_rmats = NULL;
    vector_Mat rmats;
    PyObject* pyobj_kind = NULL;
    WaveCorrectKind kind=static_cast<WaveCorrectKind>(0);

    const char* keywords[] = { "rmats", "kind", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:waveCorrect", (char**)keywords, &pyobj_rmats, &pyobj_kind) &&
        pyopencv_to(pyobj_rmats, rmats, ArgInfo("rmats", 1)) &&
        pyopencv_to(pyobj_kind, kind, ArgInfo("kind", 0)) )
    {
        ERRWRAP2(cv::detail::waveCorrect(rmats, kind));
        return pyopencv_from(rmats);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_rmats = NULL;
    vector_Mat rmats;
    PyObject* pyobj_kind = NULL;
    WaveCorrectKind kind=static_cast<WaveCorrectKind>(0);

    const char* keywords[] = { "rmats", "kind", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:waveCorrect", (char**)keywords, &pyobj_rmats, &pyobj_kind) &&
        pyopencv_to(pyobj_rmats, rmats, ArgInfo("rmats", 1)) &&
        pyopencv_to(pyobj_kind, kind, ArgInfo("kind", 0)) )
    {
        ERRWRAP2(cv::detail::waveCorrect(rmats, kind));
        return pyopencv_from(rmats);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_NMSBoxes(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    PyObject* pyobj_bboxes = NULL;
    vector_Rect2d bboxes;
    PyObject* pyobj_scores = NULL;
    vector_float scores;
    PyObject* pyobj_score_threshold = NULL;
    float score_threshold=0.f;
    PyObject* pyobj_nms_threshold = NULL;
    float nms_threshold=0.f;
    vector_int indices;
    PyObject* pyobj_eta = NULL;
    float eta=1.f;
    PyObject* pyobj_top_k = NULL;
    int top_k=0;

    const char* keywords[] = { "bboxes", "scores", "score_threshold", "nms_threshold", "eta", "top_k", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:NMSBoxes", (char**)keywords, &pyobj_bboxes, &pyobj_scores, &pyobj_score_threshold, &pyobj_nms_threshold, &pyobj_eta, &pyobj_top_k) &&
        pyopencv_to(pyobj_bboxes, bboxes, ArgInfo("bboxes", 0)) &&
        pyopencv_to(pyobj_scores, scores, ArgInfo("scores", 0)) &&
        pyopencv_to(pyobj_score_threshold, score_threshold, ArgInfo("score_threshold", 0)) &&
        pyopencv_to(pyobj_nms_threshold, nms_threshold, ArgInfo("nms_threshold", 0)) &&
        pyopencv_to(pyobj_eta, eta, ArgInfo("eta", 0)) &&
        pyopencv_to(pyobj_top_k, top_k, ArgInfo("top_k", 0)) )
    {
        ERRWRAP2(cv::dnn::NMSBoxes(bboxes, scores, score_threshold, nms_threshold, indices, eta, top_k));
        return pyopencv_from(indices);
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_NMSBoxesRotated(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    PyObject* pyobj_bboxes = NULL;
    vector_RotatedRect bboxes;
    PyObject* pyobj_scores = NULL;
    vector_float scores;
    PyObject* pyobj_score_threshold = NULL;
    float score_threshold=0.f;
    PyObject* pyobj_nms_threshold = NULL;
    float nms_threshold=0.f;
    vector_int indices;
    PyObject* pyobj_eta = NULL;
    float eta=1.f;
    PyObject* pyobj_top_k = NULL;
    int top_k=0;

    const char* keywords[] = { "bboxes", "scores", "score_threshold", "nms_threshold", "eta", "top_k", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OO:NMSBoxesRotated", (char**)keywords, &pyobj_bboxes, &pyobj_scores, &pyobj_score_threshold, &pyobj_nms_threshold, &pyobj_eta, &pyobj_top_k) &&
        pyopencv_to(pyobj_bboxes, bboxes, ArgInfo("bboxes", 0)) &&
        pyopencv_to(pyobj_scores, scores, ArgInfo("scores", 0)) &&
        pyopencv_to(pyobj_score_threshold, score_threshold, ArgInfo("score_threshold", 0)) &&
        pyopencv_to(pyobj_nms_threshold, nms_threshold, ArgInfo("nms_threshold", 0)) &&
        pyopencv_to(pyobj_eta, eta, ArgInfo("eta", 0)) &&
        pyopencv_to(pyobj_top_k, top_k, ArgInfo("top_k", 0)) )
    {
        ERRWRAP2(cv::dnn::NMSBoxes(bboxes, scores, score_threshold, nms_threshold, indices, eta, top_k));
        return pyopencv_from(indices);
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_Net_readFromModelOptimizer(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    {
    PyObject* pyobj_xml = NULL;
    String xml;
    PyObject* pyobj_bin = NULL;
    String bin;
    Net retval;

    const char* keywords[] = { "xml", "bin", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:Net_readFromModelOptimizer", (char**)keywords, &pyobj_xml, &pyobj_bin) &&
        pyopencv_to(pyobj_xml, xml, ArgInfo("xml", 0)) &&
        pyopencv_to(pyobj_bin, bin, ArgInfo("bin", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::Net::readFromModelOptimizer(xml, bin));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_bufferModelConfig = NULL;
    vector_uchar bufferModelConfig;
    PyObject* pyobj_bufferWeights = NULL;
    vector_uchar bufferWeights;
    Net retval;

    const char* keywords[] = { "bufferModelConfig", "bufferWeights", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:Net_readFromModelOptimizer", (char**)keywords, &pyobj_bufferModelConfig, &pyobj_bufferWeights) &&
        pyopencv_to(pyobj_bufferModelConfig, bufferModelConfig, ArgInfo("bufferModelConfig", 0)) &&
        pyopencv_to(pyobj_bufferWeights, bufferWeights, ArgInfo("bufferWeights", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::Net::readFromModelOptimizer(bufferModelConfig, bufferWeights));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_blobFromImage(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_scalefactor = NULL;
    double scalefactor=1.0;
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_mean = NULL;
    Scalar mean;
    PyObject* pyobj_swapRB = NULL;
    bool swapRB=false;
    PyObject* pyobj_crop = NULL;
    bool crop=false;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=CV_32F;
    Mat retval;

    const char* keywords[] = { "image", "scalefactor", "size", "mean", "swapRB", "crop", "ddepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOOO:blobFromImage", (char**)keywords, &pyobj_image, &pyobj_scalefactor, &pyobj_size, &pyobj_mean, &pyobj_swapRB, &pyobj_crop, &pyobj_ddepth) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_scalefactor, scalefactor, ArgInfo("scalefactor", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to(pyobj_swapRB, swapRB, ArgInfo("swapRB", 0)) &&
        pyopencv_to(pyobj_crop, crop, ArgInfo("crop", 0)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::blobFromImage(image, scalefactor, size, mean, swapRB, crop, ddepth));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_scalefactor = NULL;
    double scalefactor=1.0;
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_mean = NULL;
    Scalar mean;
    PyObject* pyobj_swapRB = NULL;
    bool swapRB=false;
    PyObject* pyobj_crop = NULL;
    bool crop=false;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=CV_32F;
    Mat retval;

    const char* keywords[] = { "image", "scalefactor", "size", "mean", "swapRB", "crop", "ddepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOOO:blobFromImage", (char**)keywords, &pyobj_image, &pyobj_scalefactor, &pyobj_size, &pyobj_mean, &pyobj_swapRB, &pyobj_crop, &pyobj_ddepth) &&
        pyopencv_to(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to(pyobj_scalefactor, scalefactor, ArgInfo("scalefactor", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to(pyobj_swapRB, swapRB, ArgInfo("swapRB", 0)) &&
        pyopencv_to(pyobj_crop, crop, ArgInfo("crop", 0)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::blobFromImage(image, scalefactor, size, mean, swapRB, crop, ddepth));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_blobFromImages(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    {
    PyObject* pyobj_images = NULL;
    vector_Mat images;
    PyObject* pyobj_scalefactor = NULL;
    double scalefactor=1.0;
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_mean = NULL;
    Scalar mean;
    PyObject* pyobj_swapRB = NULL;
    bool swapRB=false;
    PyObject* pyobj_crop = NULL;
    bool crop=false;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=CV_32F;
    Mat retval;

    const char* keywords[] = { "images", "scalefactor", "size", "mean", "swapRB", "crop", "ddepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOOO:blobFromImages", (char**)keywords, &pyobj_images, &pyobj_scalefactor, &pyobj_size, &pyobj_mean, &pyobj_swapRB, &pyobj_crop, &pyobj_ddepth) &&
        pyopencv_to(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to(pyobj_scalefactor, scalefactor, ArgInfo("scalefactor", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to(pyobj_swapRB, swapRB, ArgInfo("swapRB", 0)) &&
        pyopencv_to(pyobj_crop, crop, ArgInfo("crop", 0)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::blobFromImages(images, scalefactor, size, mean, swapRB, crop, ddepth));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_images = NULL;
    vector_UMat images;
    PyObject* pyobj_scalefactor = NULL;
    double scalefactor=1.0;
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_mean = NULL;
    Scalar mean;
    PyObject* pyobj_swapRB = NULL;
    bool swapRB=false;
    PyObject* pyobj_crop = NULL;
    bool crop=false;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=CV_32F;
    Mat retval;

    const char* keywords[] = { "images", "scalefactor", "size", "mean", "swapRB", "crop", "ddepth", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OOOOOO:blobFromImages", (char**)keywords, &pyobj_images, &pyobj_scalefactor, &pyobj_size, &pyobj_mean, &pyobj_swapRB, &pyobj_crop, &pyobj_ddepth) &&
        pyopencv_to(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to(pyobj_scalefactor, scalefactor, ArgInfo("scalefactor", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to(pyobj_swapRB, swapRB, ArgInfo("swapRB", 0)) &&
        pyopencv_to(pyobj_crop, crop, ArgInfo("crop", 0)) &&
        pyopencv_to(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::blobFromImages(images, scalefactor, size, mean, swapRB, crop, ddepth));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_getAvailableTargets(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    PyObject* pyobj_be = NULL;
    dnn_Backend be=static_cast<dnn_Backend>(0);
    std::vector<Target> retval;

    const char* keywords[] = { "be", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:getAvailableTargets", (char**)keywords, &pyobj_be) &&
        pyopencv_to(pyobj_be, be, ArgInfo("be", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::getAvailableTargets(be));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_imagesFromBlob(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    {
    PyObject* pyobj_blob_ = NULL;
    Mat blob_;
    PyObject* pyobj_images_ = NULL;
    vector_Mat images_;

    const char* keywords[] = { "blob_", "images_", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:imagesFromBlob", (char**)keywords, &pyobj_blob_, &pyobj_images_) &&
        pyopencv_to(pyobj_blob_, blob_, ArgInfo("blob_", 0)) &&
        pyopencv_to(pyobj_images_, images_, ArgInfo("images_", 1)) )
    {
        ERRWRAP2(cv::dnn::imagesFromBlob(blob_, images_));
        return pyopencv_from(images_);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_blob_ = NULL;
    Mat blob_;
    PyObject* pyobj_images_ = NULL;
    vector_UMat images_;

    const char* keywords[] = { "blob_", "images_", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:imagesFromBlob", (char**)keywords, &pyobj_blob_, &pyobj_images_) &&
        pyopencv_to(pyobj_blob_, blob_, ArgInfo("blob_", 0)) &&
        pyopencv_to(pyobj_images_, images_, ArgInfo("images_", 1)) )
    {
        ERRWRAP2(cv::dnn::imagesFromBlob(blob_, images_));
        return pyopencv_from(images_);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_readNet(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    {
    PyObject* pyobj_model = NULL;
    String model;
    PyObject* pyobj_config = NULL;
    String config="";
    PyObject* pyobj_framework = NULL;
    String framework="";
    Net retval;

    const char* keywords[] = { "model", "config", "framework", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:readNet", (char**)keywords, &pyobj_model, &pyobj_config, &pyobj_framework) &&
        pyopencv_to(pyobj_model, model, ArgInfo("model", 0)) &&
        pyopencv_to(pyobj_config, config, ArgInfo("config", 0)) &&
        pyopencv_to(pyobj_framework, framework, ArgInfo("framework", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNet(model, config, framework));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_framework = NULL;
    String framework;
    PyObject* pyobj_bufferModel = NULL;
    vector_uchar bufferModel;
    PyObject* pyobj_bufferConfig = NULL;
    vector_uchar bufferConfig=std::vector<uchar>();
    Net retval;

    const char* keywords[] = { "framework", "bufferModel", "bufferConfig", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:readNet", (char**)keywords, &pyobj_framework, &pyobj_bufferModel, &pyobj_bufferConfig) &&
        pyopencv_to(pyobj_framework, framework, ArgInfo("framework", 0)) &&
        pyopencv_to(pyobj_bufferModel, bufferModel, ArgInfo("bufferModel", 0)) &&
        pyopencv_to(pyobj_bufferConfig, bufferConfig, ArgInfo("bufferConfig", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNet(framework, bufferModel, bufferConfig));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_readNetFromCaffe(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    {
    PyObject* pyobj_prototxt = NULL;
    String prototxt;
    PyObject* pyobj_caffeModel = NULL;
    String caffeModel;
    Net retval;

    const char* keywords[] = { "prototxt", "caffeModel", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:readNetFromCaffe", (char**)keywords, &pyobj_prototxt, &pyobj_caffeModel) &&
        pyopencv_to(pyobj_prototxt, prototxt, ArgInfo("prototxt", 0)) &&
        pyopencv_to(pyobj_caffeModel, caffeModel, ArgInfo("caffeModel", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromCaffe(prototxt, caffeModel));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_bufferProto = NULL;
    vector_uchar bufferProto;
    PyObject* pyobj_bufferModel = NULL;
    vector_uchar bufferModel=std::vector<uchar>();
    Net retval;

    const char* keywords[] = { "bufferProto", "bufferModel", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:readNetFromCaffe", (char**)keywords, &pyobj_bufferProto, &pyobj_bufferModel) &&
        pyopencv_to(pyobj_bufferProto, bufferProto, ArgInfo("bufferProto", 0)) &&
        pyopencv_to(pyobj_bufferModel, bufferModel, ArgInfo("bufferModel", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromCaffe(bufferProto, bufferModel));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_readNetFromDarknet(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    {
    PyObject* pyobj_cfgFile = NULL;
    String cfgFile;
    PyObject* pyobj_darknetModel = NULL;
    String darknetModel;
    Net retval;

    const char* keywords[] = { "cfgFile", "darknetModel", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:readNetFromDarknet", (char**)keywords, &pyobj_cfgFile, &pyobj_darknetModel) &&
        pyopencv_to(pyobj_cfgFile, cfgFile, ArgInfo("cfgFile", 0)) &&
        pyopencv_to(pyobj_darknetModel, darknetModel, ArgInfo("darknetModel", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromDarknet(cfgFile, darknetModel));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_bufferCfg = NULL;
    vector_uchar bufferCfg;
    PyObject* pyobj_bufferModel = NULL;
    vector_uchar bufferModel=std::vector<uchar>();
    Net retval;

    const char* keywords[] = { "bufferCfg", "bufferModel", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:readNetFromDarknet", (char**)keywords, &pyobj_bufferCfg, &pyobj_bufferModel) &&
        pyopencv_to(pyobj_bufferCfg, bufferCfg, ArgInfo("bufferCfg", 0)) &&
        pyopencv_to(pyobj_bufferModel, bufferModel, ArgInfo("bufferModel", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromDarknet(bufferCfg, bufferModel));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_readNetFromModelOptimizer(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    {
    PyObject* pyobj_xml = NULL;
    String xml;
    PyObject* pyobj_bin = NULL;
    String bin;
    Net retval;

    const char* keywords[] = { "xml", "bin", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:readNetFromModelOptimizer", (char**)keywords, &pyobj_xml, &pyobj_bin) &&
        pyopencv_to(pyobj_xml, xml, ArgInfo("xml", 0)) &&
        pyopencv_to(pyobj_bin, bin, ArgInfo("bin", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromModelOptimizer(xml, bin));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_bufferModelConfig = NULL;
    vector_uchar bufferModelConfig;
    PyObject* pyobj_bufferWeights = NULL;
    vector_uchar bufferWeights;
    Net retval;

    const char* keywords[] = { "bufferModelConfig", "bufferWeights", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:readNetFromModelOptimizer", (char**)keywords, &pyobj_bufferModelConfig, &pyobj_bufferWeights) &&
        pyopencv_to(pyobj_bufferModelConfig, bufferModelConfig, ArgInfo("bufferModelConfig", 0)) &&
        pyopencv_to(pyobj_bufferWeights, bufferWeights, ArgInfo("bufferWeights", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromModelOptimizer(bufferModelConfig, bufferWeights));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_readNetFromONNX(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    {
    PyObject* pyobj_onnxFile = NULL;
    String onnxFile;
    Net retval;

    const char* keywords[] = { "onnxFile", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:readNetFromONNX", (char**)keywords, &pyobj_onnxFile) &&
        pyopencv_to(pyobj_onnxFile, onnxFile, ArgInfo("onnxFile", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromONNX(onnxFile));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_buffer = NULL;
    vector_uchar buffer;
    Net retval;

    const char* keywords[] = { "buffer", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:readNetFromONNX", (char**)keywords, &pyobj_buffer) &&
        pyopencv_to(pyobj_buffer, buffer, ArgInfo("buffer", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromONNX(buffer));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_readNetFromTensorflow(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    {
    PyObject* pyobj_model = NULL;
    String model;
    PyObject* pyobj_config = NULL;
    String config;
    Net retval;

    const char* keywords[] = { "model", "config", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:readNetFromTensorflow", (char**)keywords, &pyobj_model, &pyobj_config) &&
        pyopencv_to(pyobj_model, model, ArgInfo("model", 0)) &&
        pyopencv_to(pyobj_config, config, ArgInfo("config", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromTensorflow(model, config));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_bufferModel = NULL;
    vector_uchar bufferModel;
    PyObject* pyobj_bufferConfig = NULL;
    vector_uchar bufferConfig=std::vector<uchar>();
    Net retval;

    const char* keywords[] = { "bufferModel", "bufferConfig", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:readNetFromTensorflow", (char**)keywords, &pyobj_bufferModel, &pyobj_bufferConfig) &&
        pyopencv_to(pyobj_bufferModel, bufferModel, ArgInfo("bufferModel", 0)) &&
        pyopencv_to(pyobj_bufferConfig, bufferConfig, ArgInfo("bufferConfig", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromTensorflow(bufferModel, bufferConfig));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_readNetFromTorch(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    PyObject* pyobj_model = NULL;
    String model;
    PyObject* pyobj_isBinary = NULL;
    bool isBinary=true;
    PyObject* pyobj_evaluate = NULL;
    bool evaluate=true;
    Net retval;

    const char* keywords[] = { "model", "isBinary", "evaluate", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:readNetFromTorch", (char**)keywords, &pyobj_model, &pyobj_isBinary, &pyobj_evaluate) &&
        pyopencv_to(pyobj_model, model, ArgInfo("model", 0)) &&
        pyopencv_to(pyobj_isBinary, isBinary, ArgInfo("isBinary", 0)) &&
        pyopencv_to(pyobj_evaluate, evaluate, ArgInfo("evaluate", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readNetFromTorch(model, isBinary, evaluate));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_readTensorFromONNX(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    PyObject* pyobj_path = NULL;
    String path;
    Mat retval;

    const char* keywords[] = { "path", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:readTensorFromONNX", (char**)keywords, &pyobj_path) &&
        pyopencv_to(pyobj_path, path, ArgInfo("path", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readTensorFromONNX(path));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_readTorchBlob(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_isBinary = NULL;
    bool isBinary=true;
    Mat retval;

    const char* keywords[] = { "filename", "isBinary", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:readTorchBlob", (char**)keywords, &pyobj_filename, &pyobj_isBinary) &&
        pyopencv_to(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to(pyobj_isBinary, isBinary, ArgInfo("isBinary", 0)) )
    {
        ERRWRAP2(retval = cv::dnn::readTorchBlob(filename, isBinary));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_shrinkCaffeModel(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    PyObject* pyobj_src = NULL;
    String src;
    PyObject* pyobj_dst = NULL;
    String dst;
    PyObject* pyobj_layersTypes = NULL;
    vector_String layersTypes=std::vector<String>();

    const char* keywords[] = { "src", "dst", "layersTypes", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO|O:shrinkCaffeModel", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_layersTypes) &&
        pyopencv_to(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to(pyobj_dst, dst, ArgInfo("dst", 0)) &&
        pyopencv_to(pyobj_layersTypes, layersTypes, ArgInfo("layersTypes", 0)) )
    {
        ERRWRAP2(cv::dnn::shrinkCaffeModel(src, dst, layersTypes));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_dnn_writeTextGraph(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::dnn;

    PyObject* pyobj_model = NULL;
    String model;
    PyObject* pyobj_output = NULL;
    String output;

    const char* keywords[] = { "model", "output", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:writeTextGraph", (char**)keywords, &pyobj_model, &pyobj_output) &&
        pyopencv_to(pyobj_model, model, ArgInfo("model", 0)) &&
        pyopencv_to(pyobj_output, output, ArgInfo("output", 0)) )
    {
        ERRWRAP2(cv::dnn::writeTextGraph(model, output));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_fisheye_calibrate(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::fisheye;

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_Mat imagePoints;
    PyObject* pyobj_image_size = NULL;
    Size image_size;
    PyObject* pyobj_K = NULL;
    Mat K;
    PyObject* pyobj_D = NULL;
    Mat D;
    PyObject* pyobj_rvecs = NULL;
    vector_Mat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_Mat tvecs;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 100, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "image_size", "K", "D", "rvecs", "tvecs", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOOO:calibrate", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_image_size, &pyobj_K, &pyobj_D, &pyobj_rvecs, &pyobj_tvecs, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_image_size, image_size, ArgInfo("image_size", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 1)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 1)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::fisheye::calibrate(objectPoints, imagePoints, image_size, K, D, rvecs, tvecs, flags, criteria));
        return Py_BuildValue("(NNNNN)", pyopencv_from(retval), pyopencv_from(K), pyopencv_from(D), pyopencv_from(rvecs), pyopencv_from(tvecs));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    vector_UMat imagePoints;
    PyObject* pyobj_image_size = NULL;
    Size image_size;
    PyObject* pyobj_K = NULL;
    UMat K;
    PyObject* pyobj_D = NULL;
    UMat D;
    PyObject* pyobj_rvecs = NULL;
    vector_UMat rvecs;
    PyObject* pyobj_tvecs = NULL;
    vector_UMat tvecs;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 100, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "image_size", "K", "D", "rvecs", "tvecs", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOOO:calibrate", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints, &pyobj_image_size, &pyobj_K, &pyobj_D, &pyobj_rvecs, &pyobj_tvecs, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        pyopencv_to(pyobj_image_size, image_size, ArgInfo("image_size", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 1)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 1)) &&
        pyopencv_to(pyobj_rvecs, rvecs, ArgInfo("rvecs", 1)) &&
        pyopencv_to(pyobj_tvecs, tvecs, ArgInfo("tvecs", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::fisheye::calibrate(objectPoints, imagePoints, image_size, K, D, rvecs, tvecs, flags, criteria));
        return Py_BuildValue("(NNNNN)", pyopencv_from(retval), pyopencv_from(K), pyopencv_from(D), pyopencv_from(rvecs), pyopencv_from(tvecs));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fisheye_distortPoints(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::fisheye;

    {
    PyObject* pyobj_undistorted = NULL;
    Mat undistorted;
    PyObject* pyobj_distorted = NULL;
    Mat distorted;
    PyObject* pyobj_K = NULL;
    Mat K;
    PyObject* pyobj_D = NULL;
    Mat D;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;

    const char* keywords[] = { "undistorted", "K", "D", "distorted", "alpha", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:distortPoints", (char**)keywords, &pyobj_undistorted, &pyobj_K, &pyobj_D, &pyobj_distorted, &pyobj_alpha) &&
        pyopencv_to(pyobj_undistorted, undistorted, ArgInfo("undistorted", 0)) &&
        pyopencv_to(pyobj_distorted, distorted, ArgInfo("distorted", 1)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) )
    {
        ERRWRAP2(cv::fisheye::distortPoints(undistorted, distorted, K, D, alpha));
        return pyopencv_from(distorted);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_undistorted = NULL;
    UMat undistorted;
    PyObject* pyobj_distorted = NULL;
    UMat distorted;
    PyObject* pyobj_K = NULL;
    UMat K;
    PyObject* pyobj_D = NULL;
    UMat D;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;

    const char* keywords[] = { "undistorted", "K", "D", "distorted", "alpha", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OO:distortPoints", (char**)keywords, &pyobj_undistorted, &pyobj_K, &pyobj_D, &pyobj_distorted, &pyobj_alpha) &&
        pyopencv_to(pyobj_undistorted, undistorted, ArgInfo("undistorted", 0)) &&
        pyopencv_to(pyobj_distorted, distorted, ArgInfo("distorted", 1)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) )
    {
        ERRWRAP2(cv::fisheye::distortPoints(undistorted, distorted, K, D, alpha));
        return pyopencv_from(distorted);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fisheye_estimateNewCameraMatrixForUndistortRectify(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::fisheye;

    {
    PyObject* pyobj_K = NULL;
    Mat K;
    PyObject* pyobj_D = NULL;
    Mat D;
    PyObject* pyobj_image_size = NULL;
    Size image_size;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_P = NULL;
    Mat P;
    PyObject* pyobj_balance = NULL;
    double balance=0.0;
    PyObject* pyobj_new_size = NULL;
    Size new_size;
    PyObject* pyobj_fov_scale = NULL;
    double fov_scale=1.0;

    const char* keywords[] = { "K", "D", "image_size", "R", "P", "balance", "new_size", "fov_scale", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:estimateNewCameraMatrixForUndistortRectify", (char**)keywords, &pyobj_K, &pyobj_D, &pyobj_image_size, &pyobj_R, &pyobj_P, &pyobj_balance, &pyobj_new_size, &pyobj_fov_scale) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_image_size, image_size, ArgInfo("image_size", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_P, P, ArgInfo("P", 1)) &&
        pyopencv_to(pyobj_balance, balance, ArgInfo("balance", 0)) &&
        pyopencv_to(pyobj_new_size, new_size, ArgInfo("new_size", 0)) &&
        pyopencv_to(pyobj_fov_scale, fov_scale, ArgInfo("fov_scale", 0)) )
    {
        ERRWRAP2(cv::fisheye::estimateNewCameraMatrixForUndistortRectify(K, D, image_size, R, P, balance, new_size, fov_scale));
        return pyopencv_from(P);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_K = NULL;
    UMat K;
    PyObject* pyobj_D = NULL;
    UMat D;
    PyObject* pyobj_image_size = NULL;
    Size image_size;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_P = NULL;
    UMat P;
    PyObject* pyobj_balance = NULL;
    double balance=0.0;
    PyObject* pyobj_new_size = NULL;
    Size new_size;
    PyObject* pyobj_fov_scale = NULL;
    double fov_scale=1.0;

    const char* keywords[] = { "K", "D", "image_size", "R", "P", "balance", "new_size", "fov_scale", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOO|OOOO:estimateNewCameraMatrixForUndistortRectify", (char**)keywords, &pyobj_K, &pyobj_D, &pyobj_image_size, &pyobj_R, &pyobj_P, &pyobj_balance, &pyobj_new_size, &pyobj_fov_scale) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_image_size, image_size, ArgInfo("image_size", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_P, P, ArgInfo("P", 1)) &&
        pyopencv_to(pyobj_balance, balance, ArgInfo("balance", 0)) &&
        pyopencv_to(pyobj_new_size, new_size, ArgInfo("new_size", 0)) &&
        pyopencv_to(pyobj_fov_scale, fov_scale, ArgInfo("fov_scale", 0)) )
    {
        ERRWRAP2(cv::fisheye::estimateNewCameraMatrixForUndistortRectify(K, D, image_size, R, P, balance, new_size, fov_scale));
        return pyopencv_from(P);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fisheye_initUndistortRectifyMap(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::fisheye;

    {
    PyObject* pyobj_K = NULL;
    Mat K;
    PyObject* pyobj_D = NULL;
    Mat D;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_P = NULL;
    Mat P;
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_m1type = NULL;
    int m1type=0;
    PyObject* pyobj_map1 = NULL;
    Mat map1;
    PyObject* pyobj_map2 = NULL;
    Mat map2;

    const char* keywords[] = { "K", "D", "R", "P", "size", "m1type", "map1", "map2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OO:initUndistortRectifyMap", (char**)keywords, &pyobj_K, &pyobj_D, &pyobj_R, &pyobj_P, &pyobj_size, &pyobj_m1type, &pyobj_map1, &pyobj_map2) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_P, P, ArgInfo("P", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to(pyobj_m1type, m1type, ArgInfo("m1type", 0)) &&
        pyopencv_to(pyobj_map1, map1, ArgInfo("map1", 1)) &&
        pyopencv_to(pyobj_map2, map2, ArgInfo("map2", 1)) )
    {
        ERRWRAP2(cv::fisheye::initUndistortRectifyMap(K, D, R, P, size, m1type, map1, map2));
        return Py_BuildValue("(NN)", pyopencv_from(map1), pyopencv_from(map2));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_K = NULL;
    UMat K;
    PyObject* pyobj_D = NULL;
    UMat D;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_P = NULL;
    UMat P;
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_m1type = NULL;
    int m1type=0;
    PyObject* pyobj_map1 = NULL;
    UMat map1;
    PyObject* pyobj_map2 = NULL;
    UMat map2;

    const char* keywords[] = { "K", "D", "R", "P", "size", "m1type", "map1", "map2", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO|OO:initUndistortRectifyMap", (char**)keywords, &pyobj_K, &pyobj_D, &pyobj_R, &pyobj_P, &pyobj_size, &pyobj_m1type, &pyobj_map1, &pyobj_map2) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_P, P, ArgInfo("P", 0)) &&
        pyopencv_to(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to(pyobj_m1type, m1type, ArgInfo("m1type", 0)) &&
        pyopencv_to(pyobj_map1, map1, ArgInfo("map1", 1)) &&
        pyopencv_to(pyobj_map2, map2, ArgInfo("map2", 1)) )
    {
        ERRWRAP2(cv::fisheye::initUndistortRectifyMap(K, D, R, P, size, m1type, map1, map2));
        return Py_BuildValue("(NN)", pyopencv_from(map1), pyopencv_from(map2));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fisheye_projectPoints(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::fisheye;

    {
    PyObject* pyobj_objectPoints = NULL;
    Mat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    Mat imagePoints;
    PyObject* pyobj_rvec = NULL;
    Mat rvec;
    PyObject* pyobj_tvec = NULL;
    Mat tvec;
    PyObject* pyobj_K = NULL;
    Mat K;
    PyObject* pyobj_D = NULL;
    Mat D;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_jacobian = NULL;
    Mat jacobian;

    const char* keywords[] = { "objectPoints", "rvec", "tvec", "K", "D", "imagePoints", "alpha", "jacobian", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOO:projectPoints", (char**)keywords, &pyobj_objectPoints, &pyobj_rvec, &pyobj_tvec, &pyobj_K, &pyobj_D, &pyobj_imagePoints, &pyobj_alpha, &pyobj_jacobian) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 1)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 0)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_jacobian, jacobian, ArgInfo("jacobian", 1)) )
    {
        ERRWRAP2(cv::fisheye::projectPoints(objectPoints, imagePoints, rvec, tvec, K, D, alpha, jacobian));
        return Py_BuildValue("(NN)", pyopencv_from(imagePoints), pyopencv_from(jacobian));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    UMat objectPoints;
    PyObject* pyobj_imagePoints = NULL;
    UMat imagePoints;
    PyObject* pyobj_rvec = NULL;
    UMat rvec;
    PyObject* pyobj_tvec = NULL;
    UMat tvec;
    PyObject* pyobj_K = NULL;
    UMat K;
    PyObject* pyobj_D = NULL;
    UMat D;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_jacobian = NULL;
    UMat jacobian;

    const char* keywords[] = { "objectPoints", "rvec", "tvec", "K", "D", "imagePoints", "alpha", "jacobian", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOO|OOO:projectPoints", (char**)keywords, &pyobj_objectPoints, &pyobj_rvec, &pyobj_tvec, &pyobj_K, &pyobj_D, &pyobj_imagePoints, &pyobj_alpha, &pyobj_jacobian) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints, imagePoints, ArgInfo("imagePoints", 1)) &&
        pyopencv_to(pyobj_rvec, rvec, ArgInfo("rvec", 0)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 0)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to(pyobj_jacobian, jacobian, ArgInfo("jacobian", 1)) )
    {
        ERRWRAP2(cv::fisheye::projectPoints(objectPoints, imagePoints, rvec, tvec, K, D, alpha, jacobian));
        return Py_BuildValue("(NN)", pyopencv_from(imagePoints), pyopencv_from(jacobian));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fisheye_stereoCalibrate(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::fisheye;

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_Mat objectPoints;
    PyObject* pyobj_imagePoints1 = NULL;
    vector_Mat imagePoints1;
    PyObject* pyobj_imagePoints2 = NULL;
    vector_Mat imagePoints2;
    PyObject* pyobj_K1 = NULL;
    Mat K1;
    PyObject* pyobj_D1 = NULL;
    Mat D1;
    PyObject* pyobj_K2 = NULL;
    Mat K2;
    PyObject* pyobj_D2 = NULL;
    Mat D2;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_T = NULL;
    Mat T;
    PyObject* pyobj_flags = NULL;
    int flags=fisheye::CALIB_FIX_INTRINSIC;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 100, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints1", "imagePoints2", "K1", "D1", "K2", "D2", "imageSize", "R", "T", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOO|OOOO:stereoCalibrate", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints1, &pyobj_imagePoints2, &pyobj_K1, &pyobj_D1, &pyobj_K2, &pyobj_D2, &pyobj_imageSize, &pyobj_R, &pyobj_T, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints1, imagePoints1, ArgInfo("imagePoints1", 0)) &&
        pyopencv_to(pyobj_imagePoints2, imagePoints2, ArgInfo("imagePoints2", 0)) &&
        pyopencv_to(pyobj_K1, K1, ArgInfo("K1", 1)) &&
        pyopencv_to(pyobj_D1, D1, ArgInfo("D1", 1)) &&
        pyopencv_to(pyobj_K2, K2, ArgInfo("K2", 1)) &&
        pyopencv_to(pyobj_D2, D2, ArgInfo("D2", 1)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_T, T, ArgInfo("T", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::fisheye::stereoCalibrate(objectPoints, imagePoints1, imagePoints2, K1, D1, K2, D2, imageSize, R, T, flags, criteria));
        return Py_BuildValue("(NNNNNNN)", pyopencv_from(retval), pyopencv_from(K1), pyopencv_from(D1), pyopencv_from(K2), pyopencv_from(D2), pyopencv_from(R), pyopencv_from(T));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_objectPoints = NULL;
    vector_UMat objectPoints;
    PyObject* pyobj_imagePoints1 = NULL;
    vector_UMat imagePoints1;
    PyObject* pyobj_imagePoints2 = NULL;
    vector_UMat imagePoints2;
    PyObject* pyobj_K1 = NULL;
    UMat K1;
    PyObject* pyobj_D1 = NULL;
    UMat D1;
    PyObject* pyobj_K2 = NULL;
    UMat K2;
    PyObject* pyobj_D2 = NULL;
    UMat D2;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_T = NULL;
    UMat T;
    PyObject* pyobj_flags = NULL;
    int flags=fisheye::CALIB_FIX_INTRINSIC;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 100, DBL_EPSILON);
    double retval;

    const char* keywords[] = { "objectPoints", "imagePoints1", "imagePoints2", "K1", "D1", "K2", "D2", "imageSize", "R", "T", "flags", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOO|OOOO:stereoCalibrate", (char**)keywords, &pyobj_objectPoints, &pyobj_imagePoints1, &pyobj_imagePoints2, &pyobj_K1, &pyobj_D1, &pyobj_K2, &pyobj_D2, &pyobj_imageSize, &pyobj_R, &pyobj_T, &pyobj_flags, &pyobj_criteria) &&
        pyopencv_to(pyobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        pyopencv_to(pyobj_imagePoints1, imagePoints1, ArgInfo("imagePoints1", 0)) &&
        pyopencv_to(pyobj_imagePoints2, imagePoints2, ArgInfo("imagePoints2", 0)) &&
        pyopencv_to(pyobj_K1, K1, ArgInfo("K1", 1)) &&
        pyopencv_to(pyobj_D1, D1, ArgInfo("D1", 1)) &&
        pyopencv_to(pyobj_K2, K2, ArgInfo("K2", 1)) &&
        pyopencv_to(pyobj_D2, D2, ArgInfo("D2", 1)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 1)) &&
        pyopencv_to(pyobj_T, T, ArgInfo("T", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(retval = cv::fisheye::stereoCalibrate(objectPoints, imagePoints1, imagePoints2, K1, D1, K2, D2, imageSize, R, T, flags, criteria));
        return Py_BuildValue("(NNNNNNN)", pyopencv_from(retval), pyopencv_from(K1), pyopencv_from(D1), pyopencv_from(K2), pyopencv_from(D2), pyopencv_from(R), pyopencv_from(T));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fisheye_stereoRectify(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::fisheye;

    {
    PyObject* pyobj_K1 = NULL;
    Mat K1;
    PyObject* pyobj_D1 = NULL;
    Mat D1;
    PyObject* pyobj_K2 = NULL;
    Mat K2;
    PyObject* pyobj_D2 = NULL;
    Mat D2;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_tvec = NULL;
    Mat tvec;
    PyObject* pyobj_R1 = NULL;
    Mat R1;
    PyObject* pyobj_R2 = NULL;
    Mat R2;
    PyObject* pyobj_P1 = NULL;
    Mat P1;
    PyObject* pyobj_P2 = NULL;
    Mat P2;
    PyObject* pyobj_Q = NULL;
    Mat Q;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_newImageSize = NULL;
    Size newImageSize;
    PyObject* pyobj_balance = NULL;
    double balance=0.0;
    PyObject* pyobj_fov_scale = NULL;
    double fov_scale=1.0;

    const char* keywords[] = { "K1", "D1", "K2", "D2", "imageSize", "R", "tvec", "flags", "R1", "R2", "P1", "P2", "Q", "newImageSize", "balance", "fov_scale", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOO|OOOOOOOO:stereoRectify", (char**)keywords, &pyobj_K1, &pyobj_D1, &pyobj_K2, &pyobj_D2, &pyobj_imageSize, &pyobj_R, &pyobj_tvec, &pyobj_flags, &pyobj_R1, &pyobj_R2, &pyobj_P1, &pyobj_P2, &pyobj_Q, &pyobj_newImageSize, &pyobj_balance, &pyobj_fov_scale) &&
        pyopencv_to(pyobj_K1, K1, ArgInfo("K1", 0)) &&
        pyopencv_to(pyobj_D1, D1, ArgInfo("D1", 0)) &&
        pyopencv_to(pyobj_K2, K2, ArgInfo("K2", 0)) &&
        pyopencv_to(pyobj_D2, D2, ArgInfo("D2", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 0)) &&
        pyopencv_to(pyobj_R1, R1, ArgInfo("R1", 1)) &&
        pyopencv_to(pyobj_R2, R2, ArgInfo("R2", 1)) &&
        pyopencv_to(pyobj_P1, P1, ArgInfo("P1", 1)) &&
        pyopencv_to(pyobj_P2, P2, ArgInfo("P2", 1)) &&
        pyopencv_to(pyobj_Q, Q, ArgInfo("Q", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_newImageSize, newImageSize, ArgInfo("newImageSize", 0)) &&
        pyopencv_to(pyobj_balance, balance, ArgInfo("balance", 0)) &&
        pyopencv_to(pyobj_fov_scale, fov_scale, ArgInfo("fov_scale", 0)) )
    {
        ERRWRAP2(cv::fisheye::stereoRectify(K1, D1, K2, D2, imageSize, R, tvec, R1, R2, P1, P2, Q, flags, newImageSize, balance, fov_scale));
        return Py_BuildValue("(NNNNN)", pyopencv_from(R1), pyopencv_from(R2), pyopencv_from(P1), pyopencv_from(P2), pyopencv_from(Q));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_K1 = NULL;
    UMat K1;
    PyObject* pyobj_D1 = NULL;
    UMat D1;
    PyObject* pyobj_K2 = NULL;
    UMat K2;
    PyObject* pyobj_D2 = NULL;
    UMat D2;
    PyObject* pyobj_imageSize = NULL;
    Size imageSize;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_tvec = NULL;
    UMat tvec;
    PyObject* pyobj_R1 = NULL;
    UMat R1;
    PyObject* pyobj_R2 = NULL;
    UMat R2;
    PyObject* pyobj_P1 = NULL;
    UMat P1;
    PyObject* pyobj_P2 = NULL;
    UMat P2;
    PyObject* pyobj_Q = NULL;
    UMat Q;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_newImageSize = NULL;
    Size newImageSize;
    PyObject* pyobj_balance = NULL;
    double balance=0.0;
    PyObject* pyobj_fov_scale = NULL;
    double fov_scale=1.0;

    const char* keywords[] = { "K1", "D1", "K2", "D2", "imageSize", "R", "tvec", "flags", "R1", "R2", "P1", "P2", "Q", "newImageSize", "balance", "fov_scale", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOO|OOOOOOOO:stereoRectify", (char**)keywords, &pyobj_K1, &pyobj_D1, &pyobj_K2, &pyobj_D2, &pyobj_imageSize, &pyobj_R, &pyobj_tvec, &pyobj_flags, &pyobj_R1, &pyobj_R2, &pyobj_P1, &pyobj_P2, &pyobj_Q, &pyobj_newImageSize, &pyobj_balance, &pyobj_fov_scale) &&
        pyopencv_to(pyobj_K1, K1, ArgInfo("K1", 0)) &&
        pyopencv_to(pyobj_D1, D1, ArgInfo("D1", 0)) &&
        pyopencv_to(pyobj_K2, K2, ArgInfo("K2", 0)) &&
        pyopencv_to(pyobj_D2, D2, ArgInfo("D2", 0)) &&
        pyopencv_to(pyobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_tvec, tvec, ArgInfo("tvec", 0)) &&
        pyopencv_to(pyobj_R1, R1, ArgInfo("R1", 1)) &&
        pyopencv_to(pyobj_R2, R2, ArgInfo("R2", 1)) &&
        pyopencv_to(pyobj_P1, P1, ArgInfo("P1", 1)) &&
        pyopencv_to(pyobj_P2, P2, ArgInfo("P2", 1)) &&
        pyopencv_to(pyobj_Q, Q, ArgInfo("Q", 1)) &&
        pyopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to(pyobj_newImageSize, newImageSize, ArgInfo("newImageSize", 0)) &&
        pyopencv_to(pyobj_balance, balance, ArgInfo("balance", 0)) &&
        pyopencv_to(pyobj_fov_scale, fov_scale, ArgInfo("fov_scale", 0)) )
    {
        ERRWRAP2(cv::fisheye::stereoRectify(K1, D1, K2, D2, imageSize, R, tvec, R1, R2, P1, P2, Q, flags, newImageSize, balance, fov_scale));
        return Py_BuildValue("(NNNNN)", pyopencv_from(R1), pyopencv_from(R2), pyopencv_from(P1), pyopencv_from(P2), pyopencv_from(Q));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fisheye_undistortImage(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::fisheye;

    {
    PyObject* pyobj_distorted = NULL;
    Mat distorted;
    PyObject* pyobj_undistorted = NULL;
    Mat undistorted;
    PyObject* pyobj_K = NULL;
    Mat K;
    PyObject* pyobj_D = NULL;
    Mat D;
    PyObject* pyobj_Knew = NULL;
    Mat Knew=cv::Mat();
    PyObject* pyobj_new_size = NULL;
    Size new_size;

    const char* keywords[] = { "distorted", "K", "D", "undistorted", "Knew", "new_size", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:undistortImage", (char**)keywords, &pyobj_distorted, &pyobj_K, &pyobj_D, &pyobj_undistorted, &pyobj_Knew, &pyobj_new_size) &&
        pyopencv_to(pyobj_distorted, distorted, ArgInfo("distorted", 0)) &&
        pyopencv_to(pyobj_undistorted, undistorted, ArgInfo("undistorted", 1)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_Knew, Knew, ArgInfo("Knew", 0)) &&
        pyopencv_to(pyobj_new_size, new_size, ArgInfo("new_size", 0)) )
    {
        ERRWRAP2(cv::fisheye::undistortImage(distorted, undistorted, K, D, Knew, new_size));
        return pyopencv_from(undistorted);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_distorted = NULL;
    UMat distorted;
    PyObject* pyobj_undistorted = NULL;
    UMat undistorted;
    PyObject* pyobj_K = NULL;
    UMat K;
    PyObject* pyobj_D = NULL;
    UMat D;
    PyObject* pyobj_Knew = NULL;
    UMat Knew=cv::UMat();
    PyObject* pyobj_new_size = NULL;
    Size new_size;

    const char* keywords[] = { "distorted", "K", "D", "undistorted", "Knew", "new_size", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:undistortImage", (char**)keywords, &pyobj_distorted, &pyobj_K, &pyobj_D, &pyobj_undistorted, &pyobj_Knew, &pyobj_new_size) &&
        pyopencv_to(pyobj_distorted, distorted, ArgInfo("distorted", 0)) &&
        pyopencv_to(pyobj_undistorted, undistorted, ArgInfo("undistorted", 1)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_Knew, Knew, ArgInfo("Knew", 0)) &&
        pyopencv_to(pyobj_new_size, new_size, ArgInfo("new_size", 0)) )
    {
        ERRWRAP2(cv::fisheye::undistortImage(distorted, undistorted, K, D, Knew, new_size));
        return pyopencv_from(undistorted);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_fisheye_undistortPoints(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::fisheye;

    {
    PyObject* pyobj_distorted = NULL;
    Mat distorted;
    PyObject* pyobj_undistorted = NULL;
    Mat undistorted;
    PyObject* pyobj_K = NULL;
    Mat K;
    PyObject* pyobj_D = NULL;
    Mat D;
    PyObject* pyobj_R = NULL;
    Mat R;
    PyObject* pyobj_P = NULL;
    Mat P;

    const char* keywords[] = { "distorted", "K", "D", "undistorted", "R", "P", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:undistortPoints", (char**)keywords, &pyobj_distorted, &pyobj_K, &pyobj_D, &pyobj_undistorted, &pyobj_R, &pyobj_P) &&
        pyopencv_to(pyobj_distorted, distorted, ArgInfo("distorted", 0)) &&
        pyopencv_to(pyobj_undistorted, undistorted, ArgInfo("undistorted", 1)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_P, P, ArgInfo("P", 0)) )
    {
        ERRWRAP2(cv::fisheye::undistortPoints(distorted, undistorted, K, D, R, P));
        return pyopencv_from(undistorted);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_distorted = NULL;
    UMat distorted;
    PyObject* pyobj_undistorted = NULL;
    UMat undistorted;
    PyObject* pyobj_K = NULL;
    UMat K;
    PyObject* pyobj_D = NULL;
    UMat D;
    PyObject* pyobj_R = NULL;
    UMat R;
    PyObject* pyobj_P = NULL;
    UMat P;

    const char* keywords[] = { "distorted", "K", "D", "undistorted", "R", "P", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOO:undistortPoints", (char**)keywords, &pyobj_distorted, &pyobj_K, &pyobj_D, &pyobj_undistorted, &pyobj_R, &pyobj_P) &&
        pyopencv_to(pyobj_distorted, distorted, ArgInfo("distorted", 0)) &&
        pyopencv_to(pyobj_undistorted, undistorted, ArgInfo("undistorted", 1)) &&
        pyopencv_to(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to(pyobj_D, D, ArgInfo("D", 0)) &&
        pyopencv_to(pyobj_R, R, ArgInfo("R", 0)) &&
        pyopencv_to(pyobj_P, P, ArgInfo("P", 0)) )
    {
        ERRWRAP2(cv::fisheye::undistortPoints(distorted, undistorted, K, D, R, P));
        return pyopencv_from(undistorted);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_ipp_getIppVersion(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ipp;

    String retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ipp::getIppVersion());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ipp_setUseIPP(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ipp;

    PyObject* pyobj_flag = NULL;
    bool flag=0;

    const char* keywords[] = { "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:setUseIPP", (char**)keywords, &pyobj_flag) &&
        pyopencv_to(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(cv::ipp::setUseIPP(flag));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_ipp_setUseIPP_NotExact(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ipp;

    PyObject* pyobj_flag = NULL;
    bool flag=0;

    const char* keywords[] = { "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:setUseIPP_NotExact", (char**)keywords, &pyobj_flag) &&
        pyopencv_to(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(cv::ipp::setUseIPP_NotExact(flag));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_ipp_useIPP(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ipp;

    bool retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ipp::useIPP());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ipp_useIPP_NotExact(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ipp;

    bool retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ipp::useIPP_NotExact());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_ANN_MLP_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    Ptr<ANN_MLP> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ml::ANN_MLP::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_ANN_MLP_load(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_filepath = NULL;
    String filepath;
    Ptr<ANN_MLP> retval;

    const char* keywords[] = { "filepath", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:ANN_MLP_load", (char**)keywords, &pyobj_filepath) &&
        pyopencv_to(pyobj_filepath, filepath, ArgInfo("filepath", 0)) )
    {
        ERRWRAP2(retval = cv::ml::ANN_MLP::load(filepath));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_Boost_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    Ptr<Boost> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ml::Boost::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_Boost_load(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_filepath = NULL;
    String filepath;
    PyObject* pyobj_nodeName = NULL;
    String nodeName;
    Ptr<Boost> retval;

    const char* keywords[] = { "filepath", "nodeName", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:Boost_load", (char**)keywords, &pyobj_filepath, &pyobj_nodeName) &&
        pyopencv_to(pyobj_filepath, filepath, ArgInfo("filepath", 0)) &&
        pyopencv_to(pyobj_nodeName, nodeName, ArgInfo("nodeName", 0)) )
    {
        ERRWRAP2(retval = cv::ml::Boost::load(filepath, nodeName));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_DTrees_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    Ptr<DTrees> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ml::DTrees::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_DTrees_load(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_filepath = NULL;
    String filepath;
    PyObject* pyobj_nodeName = NULL;
    String nodeName;
    Ptr<DTrees> retval;

    const char* keywords[] = { "filepath", "nodeName", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:DTrees_load", (char**)keywords, &pyobj_filepath, &pyobj_nodeName) &&
        pyopencv_to(pyobj_filepath, filepath, ArgInfo("filepath", 0)) &&
        pyopencv_to(pyobj_nodeName, nodeName, ArgInfo("nodeName", 0)) )
    {
        ERRWRAP2(retval = cv::ml::DTrees::load(filepath, nodeName));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_EM_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    Ptr<EM> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ml::EM::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_EM_load(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_filepath = NULL;
    String filepath;
    PyObject* pyobj_nodeName = NULL;
    String nodeName;
    Ptr<EM> retval;

    const char* keywords[] = { "filepath", "nodeName", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:EM_load", (char**)keywords, &pyobj_filepath, &pyobj_nodeName) &&
        pyopencv_to(pyobj_filepath, filepath, ArgInfo("filepath", 0)) &&
        pyopencv_to(pyobj_nodeName, nodeName, ArgInfo("nodeName", 0)) )
    {
        ERRWRAP2(retval = cv::ml::EM::load(filepath, nodeName));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_KNearest_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    Ptr<KNearest> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ml::KNearest::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_KNearest_load(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_filepath = NULL;
    String filepath;
    Ptr<KNearest> retval;

    const char* keywords[] = { "filepath", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:KNearest_load", (char**)keywords, &pyobj_filepath) &&
        pyopencv_to(pyobj_filepath, filepath, ArgInfo("filepath", 0)) )
    {
        ERRWRAP2(retval = cv::ml::KNearest::load(filepath));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_LogisticRegression_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    Ptr<LogisticRegression> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ml::LogisticRegression::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_LogisticRegression_load(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_filepath = NULL;
    String filepath;
    PyObject* pyobj_nodeName = NULL;
    String nodeName;
    Ptr<LogisticRegression> retval;

    const char* keywords[] = { "filepath", "nodeName", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:LogisticRegression_load", (char**)keywords, &pyobj_filepath, &pyobj_nodeName) &&
        pyopencv_to(pyobj_filepath, filepath, ArgInfo("filepath", 0)) &&
        pyopencv_to(pyobj_nodeName, nodeName, ArgInfo("nodeName", 0)) )
    {
        ERRWRAP2(retval = cv::ml::LogisticRegression::load(filepath, nodeName));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_NormalBayesClassifier_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    Ptr<NormalBayesClassifier> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ml::NormalBayesClassifier::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_NormalBayesClassifier_load(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_filepath = NULL;
    String filepath;
    PyObject* pyobj_nodeName = NULL;
    String nodeName;
    Ptr<NormalBayesClassifier> retval;

    const char* keywords[] = { "filepath", "nodeName", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:NormalBayesClassifier_load", (char**)keywords, &pyobj_filepath, &pyobj_nodeName) &&
        pyopencv_to(pyobj_filepath, filepath, ArgInfo("filepath", 0)) &&
        pyopencv_to(pyobj_nodeName, nodeName, ArgInfo("nodeName", 0)) )
    {
        ERRWRAP2(retval = cv::ml::NormalBayesClassifier::load(filepath, nodeName));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_ParamGrid_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_minVal = NULL;
    double minVal=0.;
    PyObject* pyobj_maxVal = NULL;
    double maxVal=0.;
    PyObject* pyobj_logstep = NULL;
    double logstep=1.;
    Ptr<ParamGrid> retval;

    const char* keywords[] = { "minVal", "maxVal", "logstep", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|OOO:ParamGrid_create", (char**)keywords, &pyobj_minVal, &pyobj_maxVal, &pyobj_logstep) &&
        pyopencv_to(pyobj_minVal, minVal, ArgInfo("minVal", 0)) &&
        pyopencv_to(pyobj_maxVal, maxVal, ArgInfo("maxVal", 0)) &&
        pyopencv_to(pyobj_logstep, logstep, ArgInfo("logstep", 0)) )
    {
        ERRWRAP2(retval = cv::ml::ParamGrid::create(minVal, maxVal, logstep));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_RTrees_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    Ptr<RTrees> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ml::RTrees::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_RTrees_load(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_filepath = NULL;
    String filepath;
    PyObject* pyobj_nodeName = NULL;
    String nodeName;
    Ptr<RTrees> retval;

    const char* keywords[] = { "filepath", "nodeName", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:RTrees_load", (char**)keywords, &pyobj_filepath, &pyobj_nodeName) &&
        pyopencv_to(pyobj_filepath, filepath, ArgInfo("filepath", 0)) &&
        pyopencv_to(pyobj_nodeName, nodeName, ArgInfo("nodeName", 0)) )
    {
        ERRWRAP2(retval = cv::ml::RTrees::load(filepath, nodeName));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_SVMSGD_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    Ptr<SVMSGD> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ml::SVMSGD::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_SVMSGD_load(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_filepath = NULL;
    String filepath;
    PyObject* pyobj_nodeName = NULL;
    String nodeName;
    Ptr<SVMSGD> retval;

    const char* keywords[] = { "filepath", "nodeName", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:SVMSGD_load", (char**)keywords, &pyobj_filepath, &pyobj_nodeName) &&
        pyopencv_to(pyobj_filepath, filepath, ArgInfo("filepath", 0)) &&
        pyopencv_to(pyobj_nodeName, nodeName, ArgInfo("nodeName", 0)) )
    {
        ERRWRAP2(retval = cv::ml::SVMSGD::load(filepath, nodeName));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_SVM_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    Ptr<SVM> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ml::SVM::create());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_SVM_getDefaultGridPtr(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_param_id = NULL;
    int param_id=0;
    Ptr<ParamGrid> retval;

    const char* keywords[] = { "param_id", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:SVM_getDefaultGridPtr", (char**)keywords, &pyobj_param_id) &&
        pyopencv_to(pyobj_param_id, param_id, ArgInfo("param_id", 0)) )
    {
        ERRWRAP2(retval = cv::ml::SVM::getDefaultGridPtr(param_id));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_SVM_load(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    PyObject* pyobj_filepath = NULL;
    String filepath;
    Ptr<SVM> retval;

    const char* keywords[] = { "filepath", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:SVM_load", (char**)keywords, &pyobj_filepath) &&
        pyopencv_to(pyobj_filepath, filepath, ArgInfo("filepath", 0)) )
    {
        ERRWRAP2(retval = cv::ml::SVM::load(filepath));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_TrainData_create(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    {
    PyObject* pyobj_samples = NULL;
    Mat samples;
    PyObject* pyobj_layout = NULL;
    int layout=0;
    PyObject* pyobj_responses = NULL;
    Mat responses;
    PyObject* pyobj_varIdx = NULL;
    Mat varIdx;
    PyObject* pyobj_sampleIdx = NULL;
    Mat sampleIdx;
    PyObject* pyobj_sampleWeights = NULL;
    Mat sampleWeights;
    PyObject* pyobj_varType = NULL;
    Mat varType;
    Ptr<TrainData> retval;

    const char* keywords[] = { "samples", "layout", "responses", "varIdx", "sampleIdx", "sampleWeights", "varType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:TrainData_create", (char**)keywords, &pyobj_samples, &pyobj_layout, &pyobj_responses, &pyobj_varIdx, &pyobj_sampleIdx, &pyobj_sampleWeights, &pyobj_varType) &&
        pyopencv_to(pyobj_samples, samples, ArgInfo("samples", 0)) &&
        pyopencv_to(pyobj_layout, layout, ArgInfo("layout", 0)) &&
        pyopencv_to(pyobj_responses, responses, ArgInfo("responses", 0)) &&
        pyopencv_to(pyobj_varIdx, varIdx, ArgInfo("varIdx", 0)) &&
        pyopencv_to(pyobj_sampleIdx, sampleIdx, ArgInfo("sampleIdx", 0)) &&
        pyopencv_to(pyobj_sampleWeights, sampleWeights, ArgInfo("sampleWeights", 0)) &&
        pyopencv_to(pyobj_varType, varType, ArgInfo("varType", 0)) )
    {
        ERRWRAP2(retval = cv::ml::TrainData::create(samples, layout, responses, varIdx, sampleIdx, sampleWeights, varType));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_samples = NULL;
    UMat samples;
    PyObject* pyobj_layout = NULL;
    int layout=0;
    PyObject* pyobj_responses = NULL;
    UMat responses;
    PyObject* pyobj_varIdx = NULL;
    UMat varIdx;
    PyObject* pyobj_sampleIdx = NULL;
    UMat sampleIdx;
    PyObject* pyobj_sampleWeights = NULL;
    UMat sampleWeights;
    PyObject* pyobj_varType = NULL;
    UMat varType;
    Ptr<TrainData> retval;

    const char* keywords[] = { "samples", "layout", "responses", "varIdx", "sampleIdx", "sampleWeights", "varType", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO|OOOO:TrainData_create", (char**)keywords, &pyobj_samples, &pyobj_layout, &pyobj_responses, &pyobj_varIdx, &pyobj_sampleIdx, &pyobj_sampleWeights, &pyobj_varType) &&
        pyopencv_to(pyobj_samples, samples, ArgInfo("samples", 0)) &&
        pyopencv_to(pyobj_layout, layout, ArgInfo("layout", 0)) &&
        pyopencv_to(pyobj_responses, responses, ArgInfo("responses", 0)) &&
        pyopencv_to(pyobj_varIdx, varIdx, ArgInfo("varIdx", 0)) &&
        pyopencv_to(pyobj_sampleIdx, sampleIdx, ArgInfo("sampleIdx", 0)) &&
        pyopencv_to(pyobj_sampleWeights, sampleWeights, ArgInfo("sampleWeights", 0)) &&
        pyopencv_to(pyobj_varType, varType, ArgInfo("varType", 0)) )
    {
        ERRWRAP2(retval = cv::ml::TrainData::create(samples, layout, responses, varIdx, sampleIdx, sampleWeights, varType));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_TrainData_getSubMatrix(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    {
    PyObject* pyobj_matrix = NULL;
    Mat matrix;
    PyObject* pyobj_idx = NULL;
    Mat idx;
    PyObject* pyobj_layout = NULL;
    int layout=0;
    Mat retval;

    const char* keywords[] = { "matrix", "idx", "layout", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:TrainData_getSubMatrix", (char**)keywords, &pyobj_matrix, &pyobj_idx, &pyobj_layout) &&
        pyopencv_to(pyobj_matrix, matrix, ArgInfo("matrix", 0)) &&
        pyopencv_to(pyobj_idx, idx, ArgInfo("idx", 0)) &&
        pyopencv_to(pyobj_layout, layout, ArgInfo("layout", 0)) )
    {
        ERRWRAP2(retval = cv::ml::TrainData::getSubMatrix(matrix, idx, layout));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_matrix = NULL;
    Mat matrix;
    PyObject* pyobj_idx = NULL;
    Mat idx;
    PyObject* pyobj_layout = NULL;
    int layout=0;
    Mat retval;

    const char* keywords[] = { "matrix", "idx", "layout", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OOO:TrainData_getSubMatrix", (char**)keywords, &pyobj_matrix, &pyobj_idx, &pyobj_layout) &&
        pyopencv_to(pyobj_matrix, matrix, ArgInfo("matrix", 0)) &&
        pyopencv_to(pyobj_idx, idx, ArgInfo("idx", 0)) &&
        pyopencv_to(pyobj_layout, layout, ArgInfo("layout", 0)) )
    {
        ERRWRAP2(retval = cv::ml::TrainData::getSubMatrix(matrix, idx, layout));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_ml_TrainData_getSubVector(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ml;

    {
    PyObject* pyobj_vec = NULL;
    Mat vec;
    PyObject* pyobj_idx = NULL;
    Mat idx;
    Mat retval;

    const char* keywords[] = { "vec", "idx", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:TrainData_getSubVector", (char**)keywords, &pyobj_vec, &pyobj_idx) &&
        pyopencv_to(pyobj_vec, vec, ArgInfo("vec", 0)) &&
        pyopencv_to(pyobj_idx, idx, ArgInfo("idx", 0)) )
    {
        ERRWRAP2(retval = cv::ml::TrainData::getSubVector(vec, idx));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_vec = NULL;
    Mat vec;
    PyObject* pyobj_idx = NULL;
    Mat idx;
    Mat retval;

    const char* keywords[] = { "vec", "idx", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "OO:TrainData_getSubVector", (char**)keywords, &pyobj_vec, &pyobj_idx) &&
        pyopencv_to(pyobj_vec, vec, ArgInfo("vec", 0)) &&
        pyopencv_to(pyobj_idx, idx, ArgInfo("idx", 0)) )
    {
        ERRWRAP2(retval = cv::ml::TrainData::getSubVector(vec, idx));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_Device_getDefault(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ocl;

    Device retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ocl::Device::getDefault());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_finish(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ocl;


    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(cv::ocl::finish());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_haveAmdBlas(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ocl;

    bool retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ocl::haveAmdBlas());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_haveAmdFft(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ocl;

    bool retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ocl::haveAmdFft());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_haveOpenCL(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ocl;

    bool retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ocl::haveOpenCL());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_setUseOpenCL(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ocl;

    PyObject* pyobj_flag = NULL;
    bool flag=0;

    const char* keywords[] = { "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:setUseOpenCL", (char**)keywords, &pyobj_flag) &&
        pyopencv_to(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(cv::ocl::setUseOpenCL(flag));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_useOpenCL(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::ocl;

    bool retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ocl::useOpenCL());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_samples_addSamplesDataSearchPath(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::samples;

    PyObject* pyobj_path = NULL;
    String path;

    const char* keywords[] = { "path", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:addSamplesDataSearchPath", (char**)keywords, &pyobj_path) &&
        pyopencv_to(pyobj_path, path, ArgInfo("path", 0)) )
    {
        ERRWRAP2(cv::samples::addSamplesDataSearchPath(path));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_samples_addSamplesDataSearchSubDirectory(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::samples;

    PyObject* pyobj_subdir = NULL;
    String subdir;

    const char* keywords[] = { "subdir", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:addSamplesDataSearchSubDirectory", (char**)keywords, &pyobj_subdir) &&
        pyopencv_to(pyobj_subdir, subdir, ArgInfo("subdir", 0)) )
    {
        ERRWRAP2(cv::samples::addSamplesDataSearchSubDirectory(subdir));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_samples_findFile(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::samples;

    PyObject* pyobj_relative_path = NULL;
    String relative_path;
    PyObject* pyobj_required = NULL;
    bool required=true;
    PyObject* pyobj_silentMode = NULL;
    bool silentMode=false;
    cv::String retval;

    const char* keywords[] = { "relative_path", "required", "silentMode", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|OO:findFile", (char**)keywords, &pyobj_relative_path, &pyobj_required, &pyobj_silentMode) &&
        pyopencv_to(pyobj_relative_path, relative_path, ArgInfo("relative_path", 0)) &&
        pyopencv_to(pyobj_required, required, ArgInfo("required", 0)) &&
        pyopencv_to(pyobj_silentMode, silentMode, ArgInfo("silentMode", 0)) )
    {
        ERRWRAP2(retval = cv::samples::findFile(relative_path, required, silentMode));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_samples_findFileOrKeep(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::samples;

    PyObject* pyobj_relative_path = NULL;
    String relative_path;
    PyObject* pyobj_silentMode = NULL;
    bool silentMode=false;
    cv::String retval;

    const char* keywords[] = { "relative_path", "silentMode", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O|O:findFileOrKeep", (char**)keywords, &pyobj_relative_path, &pyobj_silentMode) &&
        pyopencv_to(pyobj_relative_path, relative_path, ArgInfo("relative_path", 0)) &&
        pyopencv_to(pyobj_silentMode, silentMode, ArgInfo("silentMode", 0)) )
    {
        ERRWRAP2(retval = cv::samples::findFileOrKeep(relative_path, silentMode));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpBool(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    bool argument=0;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpBool", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpBool(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpCString(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    char* argument=(char*)"";
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "s:dumpCString", (char**)keywords, &argument) )
    {
        ERRWRAP2(retval = cv::utils::dumpCString(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpDouble(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    double argument=0;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpDouble", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpDouble(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpFloat(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    float argument=0.f;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpFloat", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpFloat(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInputArray(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    {
    PyObject* pyobj_argument = NULL;
    Mat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpInputArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputArray(argument));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_argument = NULL;
    UMat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpInputArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputArray(argument));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInputArrayOfArrays(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    {
    PyObject* pyobj_argument = NULL;
    vector_Mat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpInputArrayOfArrays", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputArrayOfArrays(argument));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_argument = NULL;
    vector_UMat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpInputArrayOfArrays", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputArrayOfArrays(argument));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInputOutputArray(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    {
    PyObject* pyobj_argument = NULL;
    Mat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpInputOutputArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 1)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputOutputArray(argument));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(argument));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_argument = NULL;
    UMat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpInputOutputArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 1)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputOutputArray(argument));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(argument));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInputOutputArrayOfArrays(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    {
    PyObject* pyobj_argument = NULL;
    vector_Mat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpInputOutputArrayOfArrays", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 1)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputOutputArrayOfArrays(argument));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(argument));
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_argument = NULL;
    vector_UMat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpInputOutputArrayOfArrays", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 1)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputOutputArrayOfArrays(argument));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(argument));
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInt(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    int argument=0;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpInt", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInt(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpSizeT(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    size_t argument=0;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:dumpSizeT", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpSizeT(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_testAsyncArray(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    {
    PyObject* pyobj_argument = NULL;
    Mat argument;
    AsyncArray retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:testAsyncArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::testAsyncArray(argument));
        return pyopencv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_argument = NULL;
    UMat argument;
    AsyncArray retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:testAsyncArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::testAsyncArray(argument));
        return pyopencv_from(retval);
    }
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_testAsyncException(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::utils;

    AsyncArray retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::utils::testAsyncException());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getBackendName(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    PyObject* pyobj_api = NULL;
    VideoCaptureAPIs api=static_cast<VideoCaptureAPIs>(0);
    cv::String retval;

    const char* keywords[] = { "api", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:getBackendName", (char**)keywords, &pyobj_api) &&
        pyopencv_to(pyobj_api, api, ArgInfo("api", 0)) )
    {
        ERRWRAP2(retval = cv::videoio_registry::getBackendName(api));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getBackends(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    std::vector<VideoCaptureAPIs> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::videoio_registry::getBackends());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getCameraBackends(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    std::vector<VideoCaptureAPIs> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::videoio_registry::getCameraBackends());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getStreamBackends(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    std::vector<VideoCaptureAPIs> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::videoio_registry::getStreamBackends());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getWriterBackends(PyObject* , PyObject* args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    std::vector<VideoCaptureAPIs> retval;

    if(PyObject_Size(args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::videoio_registry::getWriterBackends());
        return pyopencv_from(retval);
    }

    return NULL;
}

