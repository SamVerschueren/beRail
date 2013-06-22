// Default empty project template
#ifndef BeRail_HPP_
#define BeRail_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; }}

class BeRail : public QObject
{
    Q_OBJECT

	public:
		BeRail(bb::cascades::Application *app);
		virtual ~BeRail() { };
};


#endif /* BeRail_HPP_ */
