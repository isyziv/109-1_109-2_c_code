#include <stdio.h>
#include "stack.h"

int main ()
{
    Stack   stack1, stack2, stack1_clone, stack2_clone;

    stack1 = createStack ();
    getInput (stack1);
    stack2 = createStack ();
    getInput (stack2);

    if (!depthEqual (stack1, stack2)) {
        printf ("Stack2 is not a reversed sequence to Stack1\n");
        disposeStack (stack1);
        disposeStack (stack2);
        return 0;
    }

    stack1_clone = stackClone (stack1);
    stack2_clone = stackClone (stack2);

    if (checkReverse (stack1_clone, stack2_clone))
        printf ("Yes, stack2 is a reversed stack of stack1.\n");
    else
        printf ("No, stack2 is not a reversed stack of stack1.\n");

    disposeStack (stack1_clone);
    disposeStack (stack2_clone);
    disposeStack (stack1);
    disposeStack (stack2);

} // END_main()
