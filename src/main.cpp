#define TNZU_DEFINE_INTERFACE
#include <toonz_utility.hpp>
#include <vector>

class MyFx : public tnzu::Fx {
 public:
  //
  // PORT
  //
  enum {
    PORT_INPUT,
    PORT_COUNT,
  };
  int port_count() const override { return PORT_COUNT; }
  char const* port_name(int i) const override {
    static std::array<char const*, PORT_COUNT> names = {
        "Input",
    };
    return names[i];
  }

  //
  // PARAM GROUP
  //
  enum {
    PARAM_GROUP_DEFAULT,
    PARAM_GROUP_COUNT,
  };
  int param_group_count() const override { return PARAM_GROUP_COUNT; }
  char const* param_group_name(int i) const override {
    static std::array<char const*, PARAM_GROUP_COUNT> names = {
        "Default",
    };
    return names[i];
  }

  //
  // PARAM
  //
  enum {
    PARAM_K,
    PARAM_COUNT,
  };
  int param_count() const override { return PARAM_COUNT; }
  ParamPrototype const* param_prototype(int i) const override {
    static std::array<ParamPrototype, PARAM_COUNT> const params = {
        // name, group, default, min, max
        ParamPrototype{"k", PARAM_GROUP_DEFAULT, 10, 1, 1000},
    };
    return &params[i];
  }

 public:
  int compute(Config const& config, Params const& params, Args const& args,
              cv::Mat& retimg) override try{
    DEBUG_PRINT(__FUNCTION__);
    if (args.invalid(PORT_INPUT)) {
      return 0;
    }
    cv::Mat input_img;
    input_img = args.get(PORT_INPUT);
    std::vector<cv::Mat> planes;
    cv::split(input_img, planes);
    planes[0] = ~planes[0];
    planes[1] = ~planes[1];
    planes[2] = ~planes[2];
    cv::merge(planes, retimg);
    return 0;
  } catch (cv::Exception const& e) {
    DEBUG_PRINT(e.what());
  }
};

namespace tnzu {
PluginInfo const* plugin_info() {
  static PluginInfo const info(TNZU_PP_STR(PLUGIN_NAME),    // name
                               TNZU_PP_STR(PLUGIN_VENDOR),  // vendor
                               "",                          // note
                               "https://github.com/ixixi/opentoonz_plugin_study");     // helpurl
  return &info;
}

Fx* make_fx() { return new MyFx(); }
}
