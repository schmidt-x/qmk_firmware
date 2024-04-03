LTO_ENABLE = no            # Link Time Optimization
KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
LEADER_HRM_ENABLE = yes
CONSOLE_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += font_block.c
endif

ifeq ($(strip $(OLED_GAMING)), yes)
  SRC += keyboards/ergohaven/k02/game/game.c
  SRC += keyboards/ergohaven/k02/game/drawing.c
  SRC += keyboards/ergohaven/k02/game/rndgen.c
endif
