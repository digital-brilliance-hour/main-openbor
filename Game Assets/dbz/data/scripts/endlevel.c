#include "data/scripts/story/story_clear.c"

void main()
{
  changeopenborvariant("slowmotion", 0);

  setglobalvar("Show", NULL());
  setindexedvar("Dead", NULL());

  clearStory();
}