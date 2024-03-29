#ifndef CPP3_BRICK_GAME_V_2_0_1_GUI_DESKTOP_VIEW_VIEW_TAB_WIDGET_VIEW_TAB_WIDGET_H_
#define CPP3_BRICK_GAME_V_2_0_1_GUI_DESKTOP_VIEW_VIEW_TAB_WIDGET_VIEW_TAB_WIDGET_H_

#include <QMainWindow>

#include "../NextPlayerGridWidget/NextPlayerGridWidget.hpp"
#include "GridWidget/GridWidget.h"
#include "../ui_View.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {
class ViewTabSwitcher : public QWidget {
  Q_OBJECT

 public:
  ViewTabSwitcher(Ui::View *ui, QWidget *parent = nullptr);
  ~ViewTabSwitcher() = default;

  void SetButtons();

 public slots:
  void SetExpressionCurrentIndex();
  void SetGraphCurrentIndex();
  void SetCreditCurrentIndex();
  void SetDepositCurrentIndex();
  void InitStackedWidgetIndex();

  void SetStyle(QPushButton *);

 protected:
  Ui::View *ui_;
  QWidget *parent_;
};
}  // namespace s21

#endif  // CPP3_BRICK_GAME_V_2_0_1_GUI_DESKTOP_VIEW_VIEW_TAB_WIDGET_VIEW_TAB_WIDGET_H_