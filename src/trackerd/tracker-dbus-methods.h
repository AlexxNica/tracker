/* Tracker
 * Copyright (C) 2005, Mr Jamie McCracken (jamiemcc@gnome.org)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <mysql/mysql.h>
#include "tracker-dbus.h"
#include "tracker-db.h"






void	tracker_set_error 		(DBusRec 	  *rec,
					 const char	  *fmt, 
	   	 			 ...);

char *	tracker_get_metadata 		(DBConnection *db_con, const char *service, const char *id, const char *key);

void	tracker_set_metadata 		(DBConnection *db_con, const char *service, const char *id, const char *key, const char *value, gboolean overwrite);

int	tracker_get_file_id 			(DBConnection *db_con, const char *uri, gboolean create_record);

void	tracker_add_query_result_to_dict 	(MYSQL_RES *res, DBusMessageIter *iter_dict);

char *	tracker_format_search_terms 		(const char *str, gboolean *do_bool_search);


char **	tracker_get_query_result_as_array 	(MYSQL_RES *res, int *row_count);

void	tracker_dbus_method_get_stats	 	(DBusRec *rec);
void	tracker_dbus_method_get_services 	(DBusRec *rec);
void	tracker_dbus_method_get_version 	(DBusRec *rec);

