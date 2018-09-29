// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef main_component_h
#define main_component_h
#include <FL/Fl.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Slider.H>
#include <list>
#include <vector>
#include <memory>
class Patch;
class Patch_Bank;
class Parameter_Collection;
class Parameter_Access;
class PA_Integer;
class PA_Boolean;
class PA_Choice;
class P_General;
class Association;
class Midi_Out_Queue;
class Fl_Choice;
class Fl_Check_Button;
class Fl_Slider;
class Fl_Dial;
template <class T> class Fl_Widget_Ex; 
template <class T> class Fl_Valuator_Ex; 
typedef Fl_Widget_Ex<Fl_Choice> Fl_Choice_Ex;
typedef Fl_Widget_Ex<Fl_Check_Button> Fl_Check_Button_Ex;
typedef Fl_Widget_Ex<Fl_Group> Fl_Group_Ex;
typedef Fl_Valuator_Ex<Fl_Slider> Fl_Slider_Ex;
typedef Fl_Valuator_Ex<Fl_Dial> Fl_Dial_Ex;
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>

class Main_Component : public Fl_Group {
public:
  Main_Component(int X, int Y, int W, int H, const char *L = 0);
private:
  void init(); 
public:
  ~Main_Component(); 
  void reset_description_text(); 
  unsigned get_patch_number() const; 
private:
  void set_patch_number(unsigned no); 
public:
  void set_nth_patch(unsigned nth, const Patch &pat); 
  void refresh_bank_browser(); 
  void refresh_patch_display(); 
private:
  Association *setup_slider(Fl_Slider_Ex *sl, Parameter_Access &p, int flags = 0); 
  void setup_checkbox(Fl_Check_Button_Ex *chk, Parameter_Access &p, int flags = 0); 
  void setup_choice(Fl_Choice_Ex *cb, Parameter_Access &p, int flags = 0); 
  void setup_boxes(bool enable, const Parameter_Collection &pc, Fl_Group_Ex *boxes[], unsigned nboxes); 
  void update_midi_outs(); 
  void on_selected_patch(); 
  void on_changed_midi_out(); 
public:
  Fl_Button *btn_import;
private:
  inline void cb_btn_import_i(Fl_Button*, void*);
  static void cb_btn_import(Fl_Button*, void*);
public:
  Fl_Button *btn_export;
private:
  inline void cb_btn_export_i(Fl_Button*, void*);
  static void cb_btn_export(Fl_Button*, void*);
  void on_clicked_import(); 
  void on_clicked_export(); 
  void on_clicked_change(); 
  void on_clicked_new(); 
  void on_clicked_copy(); 
  void on_clicked_delete(); 
  void on_clicked_send(); 
  void on_edited_patch_name(); 
  static void on_edited_parameter(Fl_Widget *w, void *user_data); 
  static void on_enter_parameter_control(Fl_Widget *w, void *user_data); 
  static void on_leave_parameter_control(Fl_Widget *w, void *user_data); 
public:
  Fl_Hold_Browser *br_bank;
private:
  inline void cb_br_bank_i(Fl_Hold_Browser*, void*);
  static void cb_br_bank(Fl_Hold_Browser*, void*);
  std::unique_ptr<Patch_Bank> pbank_; 
  std::unique_ptr<P_General> pgen_; 
  std::vector<std::unique_ptr<Association>> assoc_; 
  std::list<Association *> assoc_entered_; 
  std::unique_ptr<Midi_Out_Queue> midi_out_q_; 
public:
  Fl_Choice *ch_midi_out;
private:
  inline void cb_ch_midi_out_i(Fl_Choice*, void*);
  static void cb_ch_midi_out(Fl_Choice*, void*);
public:
  Fl_Button *btn_change;
private:
  inline void cb_btn_change_i(Fl_Button*, void*);
  static void cb_btn_change(Fl_Button*, void*);
public:
  Fl_Check_Button_Ex *chk_noise_gate;
  Fl_Group_Ex *box_ng1;
  Fl_Group_Ex *box_ng2;
  Fl_Group_Ex *box_ng3;
  Fl_Group_Ex *box_ng4;
  Fl_Group_Ex *box_ng5;
  Fl_Group_Ex *box_ng6;
  Fl_Check_Button_Ex *chk_compressor;
  Fl_Group_Ex *box_cpr1;
  Fl_Group_Ex *box_cpr2;
  Fl_Group_Ex *box_cpr3;
  Fl_Group_Ex *box_cpr4;
  Fl_Group_Ex *box_cpr5;
  Fl_Group_Ex *box_cpr6;
  Fl_Check_Button_Ex *chk_equalizer;
  Fl_Group_Ex *box_eq1;
  Fl_Group_Ex *box_eq2;
  Fl_Group_Ex *box_eq4;
  Fl_Group_Ex *box_eq5;
  Fl_Group_Ex *box_eq7;
  Fl_Group_Ex *box_eq8;
  Fl_Group_Ex *box_eq3;
  Fl_Group_Ex *box_eq6;
  Fl_Group_Ex *box_eq9;
  Fl_Check_Button_Ex *chk_filter;
  Fl_Group_Ex *box_flt1;
  Fl_Group_Ex *box_flt2;
  Fl_Group_Ex *box_flt3;
  Fl_Group_Ex *box_flt4;
  Fl_Group_Ex *box_flt5;
  Fl_Group_Ex *box_flt6;
  Fl_Group_Ex *box_flt7;
  Fl_Group_Ex *box_flt8;
  Fl_Group_Ex *box_flt9;
  Fl_Group_Ex *box_flt10;
  Fl_Group_Ex *box_flt11;
  Fl_Group_Ex *box_flt12;
  Fl_Group_Ex *box_flt13;
  Fl_Group_Ex *box_flt14;
  Fl_Choice_Ex *cb_filter;
  Fl_Check_Button_Ex *chk_pitch;
  Fl_Group_Ex *box_pit1;
  Fl_Group_Ex *box_pit2;
  Fl_Group_Ex *box_pit3;
  Fl_Group_Ex *box_pit4;
  Fl_Group_Ex *box_pit5;
  Fl_Group_Ex *box_pit6;
  Fl_Group_Ex *box_pit7;
  Fl_Group_Ex *box_pit8;
  Fl_Group_Ex *box_pit9;
  Fl_Group_Ex *box_pit10;
  Fl_Group_Ex *box_pit11;
  Fl_Group_Ex *box_pit12;
  Fl_Group_Ex *box_pit13;
  Fl_Group_Ex *box_pit14;
  Fl_Choice_Ex *cb_pitch;
  Fl_Check_Button_Ex *chk_chorus;
  Fl_Group_Ex *box_cho1;
  Fl_Group_Ex *box_cho2;
  Fl_Group_Ex *box_cho3;
  Fl_Group_Ex *box_cho4;
  Fl_Group_Ex *box_cho5;
  Fl_Group_Ex *box_cho6;
  Fl_Group_Ex *box_cho7;
  Fl_Group_Ex *box_cho8;
  Fl_Group_Ex *box_cho9;
  Fl_Group_Ex *box_cho10;
  Fl_Group_Ex *box_cho11;
  Fl_Group_Ex *box_cho12;
  Fl_Group_Ex *box_cho13;
  Fl_Group_Ex *box_cho14;
  Fl_Choice_Ex *cb_chorus;
  Fl_Check_Button_Ex *chk_delay;
  Fl_Group_Ex *box_del1;
  Fl_Group_Ex *box_del2;
  Fl_Group_Ex *box_del3;
  Fl_Group_Ex *box_del4;
  Fl_Group_Ex *box_del5;
  Fl_Group_Ex *box_del6;
  Fl_Group_Ex *box_del7;
  Fl_Group_Ex *box_del8;
  Fl_Group_Ex *box_del9;
  Fl_Group_Ex *box_del10;
  Fl_Group_Ex *box_del11;
  Fl_Group_Ex *box_del12;
  Fl_Group_Ex *box_del13;
  Fl_Group_Ex *box_del14;
  Fl_Choice_Ex *cb_delay;
  Fl_Check_Button_Ex *chk_reverb;
  Fl_Group_Ex *box_rev1;
  Fl_Group_Ex *box_rev2;
  Fl_Group_Ex *box_rev3;
  Fl_Group_Ex *box_rev4;
  Fl_Group_Ex *box_rev5;
  Fl_Group_Ex *box_rev6;
  Fl_Group_Ex *box_rev7;
  Fl_Group_Ex *box_rev8;
  Fl_Group_Ex *box_rev9;
  Fl_Group_Ex *box_rev10;
  Fl_Group_Ex *box_rev11;
  Fl_Group_Ex *box_rev12;
  Fl_Group_Ex *box_rev13;
  Fl_Group_Ex *box_rev14;
  Fl_Choice_Ex *cb_reverb;
  Fl_Button *btn_send;
private:
  inline void cb_btn_send_i(Fl_Button*, void*);
  static void cb_btn_send(Fl_Button*, void*);
public:
  Fl_Box *txt_description;
  Fl_Check_Button *chk_realtime;
  Fl_Button *btn_new;
private:
  inline void cb_btn_new_i(Fl_Button*, void*);
  static void cb_btn_new(Fl_Button*, void*);
public:
  Fl_Button *btn_copy;
private:
  inline void cb_btn_copy_i(Fl_Button*, void*);
  static void cb_btn_copy(Fl_Button*, void*);
public:
  Fl_Button *btn_delete;
private:
  inline void cb_btn_delete_i(Fl_Button*, void*);
  static void cb_btn_delete(Fl_Button*, void*);
public:
  Fl_Input *txt_patch_name;
private:
  inline void cb_txt_patch_name_i(Fl_Input*, void*);
  static void cb_txt_patch_name(Fl_Input*, void*);
public:
  Fl_Slider_Ex *sl_tap_tempo;
  Fl_Check_Button_Ex *chk_relay1;
  Fl_Check_Button_Ex *chk_relay2;
  Fl_Choice_Ex *cb_routing;
  Fl_Slider_Ex *sl_out_level;
  Fl_Box *lbl_tap_tempo;
  Fl_Box *lbl_out_level;
};
#endif
