LTO_ENABLE = yes           # Link Time Optimization
KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE = yes
HRM_ENABLE = yes
# CONSOLE_ENABLE = yes

SRC += helper.c

ifeq ($(strip $(HRM_ENABLE)), yes)
	OPT_DEFS += -DHRM_ENABLE
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += font_block.c
endif

ifeq ($(strip $(OLED_GAMING)), yes)
  SRC += keyboards/ergohaven/k02/game/game.c
  SRC += keyboards/ergohaven/k02/game/drawing.c
  SRC += keyboards/ergohaven/k02/game/rndgen.c
endif
