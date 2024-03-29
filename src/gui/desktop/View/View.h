#ifndef CPP3_BRICK_GAME_V_2_0_1_GUI_DESKTOP_VIEW_VIEW_H_
#define CPP3_BRICK_GAME_V_2_0_1_GUI_DESKTOP_VIEW_VIEW_H_

#include <QInputDialog>
#include <QKeyEvent>
#include <QLabel>
#include <QLayoutItem>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>

#include "../../../brick_game/common/fsm_types.h"
#include "../../../brick_game/common/parameters/parameters.h"
#include "../../../brick_game/snake/controller/controller.h"
#include "../../../brick_game/tetris/fsm/fsm.h"
#include "GridWidget/GridWidget.h"
#include "NextPlayerGridWidget/NextPlayerGridWidget.hpp"
#include "ViewTabSwitcher/ViewTabSwitcher.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {

class View : public QMainWindow {
  Q_OBJECT

 public:
  explicit View(QWidget *parent = nullptr);
  ~View();

  void HandleSignal(SignalType signal_type);
  void UpdateTetris();
  void UpdateSnake();

 signals:
  void SignalMoveUp();
  void SignalMoveDown();
  void SignalMoveLeft();
  void SignalMoveRight();
  void SignalEscapeButton();
  void SignalEnterButton();
  void SignalPauseButton();
  void SignalNoneButton();

 protected:
  void keyPressEvent(QKeyEvent *event) override;
 private slots:
  void StartTetrisGame();
  void StartSnakeGame();

 private:
  Ui::View *ui_;

  ViewTabSwitcher *view_tab_switcher_;
  SignalType signal_type_{};

  Board t_board_{};
  GameStatus game_status_{};

  Player t_player_{};
  Player t_next_player_{};
  Player t_predict_player_{};
  State t_state_ = kStart;
  Records t_records_{};
  Parameters t_parameters_{};

  long long t_time_in_secs_{};

  Board s_board_{};
  GameStatus s_game_status_{};
  Player s_player_{};
  State s_state_ = kStart;
  Records s_records_{};
  Cell s_fruit_{};
  long long s_time_in_secs_{};

  Parameters s_parameters_{};

  Parameters *p_t_parameters_;
  Parameters *p_s_parameters_;

  QTimer *timer_;

  CurrentGame current_game_{CurrentGame::kTetris};

  void InitializeUI();
  void PrintTetrisRecords();
  void PrintSnakeRecords();
  void PrintState(State state, QLabel *label);
};
}  // namespace s21
#endif  // CPP3_BRICK_GAME_V_2_0_1_GUI_DESKTOP_VIEW_VIEW_H_
