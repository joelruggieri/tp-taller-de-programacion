/*
 * View.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEW_H_
#define VIEW_H_

class View {
public:
	View();
	virtual ~View();
	virtual void dibujarse()=0;
};

#endif /* VIEW_H_ */
